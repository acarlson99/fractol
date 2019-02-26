/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:25:45 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 21:21:14 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t		calc_point(t_vect3 *z, unsigned iters, int clr)
{
	t_vect3			old;
	t_vect3			new;
	unsigned		i;

	i = 0;
	old = (t_vect3){.x = 0, .y = 0, .z = 0};
	new = (t_vect3){.x = 0, .y = 0, .z = 0};
	while ((i < iters) && ((new.x * new.x + new.y * new.y) <= 4.0))
	{
		old = new;
		new.x = old.x * old.x - old.y * old.y + z->x;
		new.y = fabs(2.0 * old.x * old.y) + z->y;
		++i;
	}
	return (get_color(iters, i, clr));
}

void				*calc_ship(t_targ *p)
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
			PLT(p->f->img, calc_point(n, p->f->iters, p->f->colors),\
				x, y, p->f->size_line, p->f->bits_per_pixel);
			free(n);
			++y;
		}
		++x;
	}
	return (NULL);
}
