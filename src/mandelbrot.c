/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:22:26 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 16:13:44 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** static int	calc_point(long double i, long double j, unsigned iters)
** {
**	int			z;
**
**	z = 0;
**	for (; iters; iters--)
**	{
**	}
** }
*/

void		*calc_mandelbrot(t_targ *p)
{
	int					i;
	int					j;
	// long double		real;
	// long double		complex;

	i = 0;
	p->f->img[p->start_y] = 100;
	while (i < p->f->windowheight)
	{
		j = p->start_y;
		while (j < p->end_y)
			PLT(p->f->img, CLR(0, 255, 0, 254), j++, i, p->f->size_line,\
				p->f->bits_per_pixel);
		++i;
	}
	return (NULL);
}
