/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:29:22 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 00:32:05 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"

# define USGMSG "usage: ./fractol [athw]=arg\n"
# define HTMAX 10000
# define WDMAX 10000
# define DEFAULTHEIGHT 1000
# define DEFAULTWIDTH 1000
# define NUMBANDS 4

# define MAXKEYS 300

typedef struct			s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_image;
	char			*img;

	int				windowheight;
	int				windowwidth;
	unsigned		type;
	unsigned		arg;

	long double		min_x;
	long double		min_y;
	long double		max_x;
	long double		max_y;

	int				bits_per_pixel;
	int				size_line;
	int				endian;

	int				update;
}						t_fract;

typedef void		*(*t_fnptr)();
typedef void		(*t_kfun)();

/*
** Dispatch tables
*/

extern const char		*g_fracts[];
extern const t_fnptr	g_funcs[];
extern const t_kfun		g_keycmds[MAXKEYS];

t_fract					*get_cmd(int argc, char **argv);

void					init_struct(t_fract *f);

/*
** Key functions
*/

void		exit_prog(t_fract *f);

/*
** Fractal calculations
*/

void					*calc_mandelbrot(t_fract *f, int start_y, int end_y);
void					*calc_julia(t_fract *f);
void					*calc_ship(t_fract *f);
void					*calc_sierpinski(t_fract *f);
void					*calc_buddha(t_fract *f);
void					*calc_lyapunov(t_fract *f);

#endif
