/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:22:26 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/24 15:34:34 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t		get_color(int itmax, int i)
{
	if (itmax == i)
		return (0xFFFFFF);
	return (0);
}

static int32_t		calc_point(t_vect3 *z, unsigned iters)
{
	t_vect3			old;
	t_vect3			new;
	unsigned		i;
	
	i = 0;
	old = (t_vect3){.x = 0, .y = 0, .z = 0};
	new = (t_vect3){.x = 0, .y = 0, .z = 0};
	while ((i < iters) && ((new.x * new.x + new.y * new.y) <= 4.0f))
	{
		old = new;
		new.x = old.x * old.x - old.y * old.y + z->x;
		new.y = 2.0f * old.x * old.y + z->y;
		++i;
	}
	return (get_color(iters, i));
}

void				*calc_mandelbrot(t_targ *p)
{
	int					x;
	int					y;
	t_vect3				*n;

	(void)n;
	x = 0;
	p->f->img[p->start_y] = 100;
	while (x < p->f->windowheight)
	{
		y = p->start_y;
		while (y < p->end_y)
		{
			n = scale_point(p->f, x, y);
			PLT(p->f->img, calc_point(n,\
					p->f->iters), x, y, p->f->size_line, p->f->bits_per_pixel);
			free(n);
			++y;
		}
		++x;
	}
	return (NULL);
}
