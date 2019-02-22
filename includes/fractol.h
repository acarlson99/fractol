/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:29:22 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/21 19:51:33 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include "libft.h"

# define USGMSG "usage: ./fractol [width] [height] [type] [other_args]\n"

typedef struct			s_fract
{
	unsigned		height;
	unsigned		width;
	unsigned		type;
	unsigned		arg;
}						t_fract;

typedef void		*(*t_fnptr)();

extern t_fnptr	g_funcs[];
extern char		*g_fracts[];

t_fract					*get_cmd(int argc, char **argv);

void					*calc_mandelbrot(t_fract *f);
void					*calc_julia(t_fract *f);
void					*calc_ship(t_fract *f);
void					*calc_sierpinski(t_fract *f);
void					*calc_buddha(t_fract *f);
void					*calc_lyapunov(t_fract *f);

#endif
