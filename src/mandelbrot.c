/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:22:26 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 16:21:27 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** static int32_t		calc_point(t_vect3 *z, unsigned iters, int clr, int rot)
** {
** 	t_vect3			old;
** 	t_vect3			new;
** 	unsigned		i;
** 
** 	i = 0;
** 	old = (t_vect3){.x = 0, .y = 0, .z = 0};
** 	new = (t_vect3){.x = 0, .y = 0, .z = 0};
** 	while ((i < iters) && ((new.x * new.x + new.y * new.y) <= 4.0))
** 	{
** 		old = new;
** 		new.x = old.x * old.x - old.y * old.y + z->x;
** 		new.y = 2.0 * old.x * old.y + z->y;
** 		++i;
** 	}
** 	return (get_color(iters, i, clr, rot));
** }
*/

static int32_t		calc_point(t_vect3 *z, t_fract *f)
{
	double		zx;
	double		zy;
	double		xtmp;
	unsigned	i;

	zx = z->x;
	zy = z->y;
	xtmp = 0;
	i = 0;
	while (zx * zx + zy * zy < 4 && i < f->iters)
	{
		xtmp = pow((zx * zx + zy * zy), (f->arg / 2))
			* cos(f->arg * atan2(zy, zx)) + z->x;
		zy = pow((zx * zx + zy * zy), (f->arg / 2))
			* sin(f->arg * atan2(zy, zx)) + z->y;
		zx = xtmp;
		++i;
	}
	return (get_color(f->iters, i, f->colors, f->rot));
}

void				*calc_mandelbrot(t_targ *p)
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
			// PLT(p->f->img, calc_point(n, p->f->iters, p->f->colors, p->f->rot),
			PLT(p->f->img, calc_point(n, p->f),
				x, y, p->f->size_line, p->f->bits_per_pixel);
			free(n);
			++y;
		}
		++x;
	}
	return (NULL);
}
