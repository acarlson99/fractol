/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lyapunov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:25:46 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 16:01:48 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define F(n,s) ((s & (1 << n)))

static int32_t		calc_point(t_vect3 *z, t_fract *f)
{
	int			r;
	unsigned	s = 0;

	(void)z;
	(void)f;
	(void)r;
	(void)s;
	// r_n = a if S_n == A
	// r_n = b if S_n == B
	// x_0 = 0.5
	// x_(n+1) = r_n * x_n(1 - x_n)
	return (F(0, f->arg) ? FT_INT_MAX : 0);
}

void				*calc_lyapunov(t_targ *p)
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
			PLT(p->f->img, calc_point(n, p->f),
				x, y, p->f->size_line, p->f->bits_per_pixel);
			free(n);
			++y;
		}
		++x;
	}
	return (NULL);
}
