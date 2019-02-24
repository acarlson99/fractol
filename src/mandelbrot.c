/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:22:26 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 19:56:07 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** from math import log, log2
**
** MAX_ITER = 80
**
** def mandelbrot(c):
** z = 0
** n = 0
** while abs(z) <= 2 and n < MAX_ITER:
** z = z*z + c
** n += 1
**
** if n == MAX_ITER:
** return MAX_ITER
**
** return n + 1 - log(log2(abs(z)))
*/

#include <stdio.h>	// TODO: delete

/*
** TODO: remember to treat x and y differently
** x is real part.  y is imag part
*/

static int32_t		calc_point(t_vect3 *n, unsigned iters)
{
	t_vect3			z;
	double			tmp;
	
	(void)n;
	(void)iters;
	z = (t_vect3){.x = 0, .y = 0, .z = 0};
	// printf("%f %f\n", n->x, n->y);	// TODO: delete
	while (fabs(z.x) <= 2 && fabs(z.y) <= 2 && iters--)
	{
		// z = z * z + c	// TODO: figure out imaginary numbers
	}
	// printf("%f %f\n", z.x, z.y);
	if (iters)
		return (FT_INT_MAX);
	return (0);
}

void				*calc_mandelbrot(t_targ *p)
{
	int					i;
	int					j;
	t_vect3				*n;

	(void)n;
	i = 0;
	p->f->img[p->start_y] = 100;
	while (i < p->f->windowheight)
	{
		j = p->start_y;
		while (j < p->end_y)
		{
			n = scale_point(p->f, i, j);
			PLT(p->f->img, calc_point(n,\
					p->f->iters), j, i, p->f->size_line, p->f->bits_per_pixel);
			free(n);
			++j;
		}
		++i;
	}
	return (NULL);
}
