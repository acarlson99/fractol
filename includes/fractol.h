/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:29:22 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/21 22:45:38 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include "libft.h"

# define USGMSG "usage: ./fractol [athw]=arg\n"
# define HTMAX 10000
# define WDMAX 10000

typedef struct			s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;

	unsigned		windowheight;
	unsigned		windowwidth;
	unsigned		type;
	unsigned		arg;
	long double		min_x;
	long double		min_y;
	long double		max_x;
	long double		max_y;
}						t_fract;

typedef void		*(*t_fnptr)();

extern t_fnptr	g_funcs[];
extern char		*g_fracts[];

t_fract					*get_cmd(int argc, char **argv);

void					init_struct(t_fract *f);

void					*calc_mandelbrot(t_fract *f);
void					*calc_julia(t_fract *f);
void					*calc_ship(t_fract *f);
void					*calc_sierpinski(t_fract *f);
void					*calc_buddha(t_fract *f);
void					*calc_lyapunov(t_fract *f);

#endif
