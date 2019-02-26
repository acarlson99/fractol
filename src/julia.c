/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:25:15 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 21:21:02 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t		calc_point(t_vect3 *z, t_vect3 *c, unsigned iters, int clr)
{
	t_vect3			old;
	unsigned		i;

	i = 0;
	(void)c;
	(void)z;
	old = (t_vect3){.x = z->x, .y = z->y, .z = 0};
	while ((i < iters) && ((z->x * z->x + z->y * z->y) <= 4.0f))
	{
		old = (t_vect3){.x = z->x, .y = z->y, .z = z->z};
		z->x = old.x * old.x - old.y * old.y + c->x;
		z->y = 2 * old.x * old.y + c->y;
		++i;
	}
	return (get_color(iters, i, clr));
}

void				*calc_julia(t_targ *p)
{
	int					x;
	int					y;
	t_vect3				*n;

	x = 0;
	while (x < p->f->windowheight)
	{
		y = p->start_y;
		while (y < p->end_y)
		{
			n = scale_point(p->f, x, y);
			PLT(p->f->img, calc_point(n, p->f->c, p->f->iters, p->f->colors),\
				x, y, p->f->size_line, p->f->bits_per_pixel);
			free(n);
			++y;
		}
		++x;
	}
	return (NULL);
}
