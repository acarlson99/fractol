/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:22:26 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 16:45:57 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	calc_point(long double real, long double imag, unsigned iters)
{
	long double		z_real;
	long double		z_imag;

	z_real = 0;
	z_imag = 0;
	char green = 0;
	char blue = 0;
	for (; iters; iters--)
	{
		if (fabsl(real - imag) > 42)
			++blue;
		else
			++green;
	}
	return (CLR(0, green, blue, 0));
}


void		*calc_mandelbrot(t_targ *p)
{
	int					i;
	int					j;
	long double		real;
	long double		imag;

	i = 0;
	real = 0;
	imag = 0;
	p->f->img[p->start_y] = 100;
	while (i < p->f->windowheight)
	{
		j = p->start_y;
		while (j < p->end_y)
		{
			PLT(p->f->img, calc_point(i, j, p->f->iters), j,\
				i, p->f->size_line, p->f->bits_per_pixel);
			++j;
		}
		++i;
	}
	return (NULL);
}
