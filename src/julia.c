/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:25:15 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 14:58:20 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t		calc_point_2(t_vect3 *z, t_fract *f)
{
	t_vect3			old;
	unsigned		i;

	i = 0;
	old = (t_vect3){.x = z->x, .y = z->y, .z = 0};
	while ((i < f->iters) && ((z->x * z->x + z->y * z->y) <= 4.0f))
	{
		old = (t_vect3){.x = z->x, .y = z->y, .z = z->z};
		z->x = old.x * old.x - old.y * old.y + f->c->x;
		z->y = 2 * old.x * old.y + f->c->y;
		++i;
	}
	return (get_color(f->iters, i, f->colors, f->rot));
}

static int32_t		calc_point_n(t_vect3 *z, t_fract *f)
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
			* cos(f->arg * atan2(zy, zx)) + f->c->x;
		zy = pow((zx * zx + zy * zy), (f->arg / 2))
			* sin(f->arg * atan2(zy, zx)) + f->c->y;
		zx = xtmp;
		++i;
	}
	return (get_color(f->iters, i, f->colors, f->rot));
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
			p->f->arg == 2 ? PLT(p->f->img, calc_point_2(n, p->f), x, y,
	p->f->size_line, p->f->bits_per_pixel) : PLT(p->f->img,
	calc_point_n(n, p->f), x, y, p->f->size_line, p->f->bits_per_pixel);
			free(n);
			++y;
		}
		++x;
	}
	return (NULL);
}
