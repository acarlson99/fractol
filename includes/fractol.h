/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:29:22 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 17:03:45 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>
# include "mlx_keys_macos.h"
# include "mlx.h"
# include "libft.h"

# define USGMSG "usage: ./fractol [athw]=arg\n"
# define HTMAX 10000
# define WDMAX 10000
# define DEFAULTHEIGHT 1000
# define DEFAULTWIDTH 1000
# define NUMBANDS 4

# define MAXKEYS 300

/*
** x, y, mlx line length, mlx bits per pixel
*/

# define IDX(X, Y, L, BPP) ((Y) * (L)) + ((X) * ((BPP) / 8))

/*
** mlx img, color
*/

# define PLT(G, C, X, Y, L, BPP) ((*(int32_t *)&G[IDX(X,Y,L,BPP)] = C))

/*
** red, green, blue, alpha
*/

# define CLR(R, G, B, A) ((int32_t)((A<<0x18) | (R<<0x10) | (G<<0x8) | (B)))

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

	unsigned		iters;

	long double		min_x;
	long double		min_y;
	long double		max_x;
	long double		max_y;

	int				bits_per_pixel;
	int				size_line;
	int				endian;

	int				update;
}						t_fract;

typedef struct			s_targ
{
	t_fract		*f;
	int			start_y;
	int			end_y;
}						t_targ;

typedef void		*(*t_fnptr)();
typedef void		(*t_kfun)();

/*
** Dispatch tables
*/

extern const char		*g_fracts[];
extern const t_fnptr	g_funcs[];
extern const t_kfun		g_keycmds[MAXKEYS];

/*
** Arg parsing
*/

t_fract					*get_cmd(int argc, char **argv);

/*
** Struct manipulation
*/

void					init_struct(t_fract *f);
void					*make_thread_arg(t_fract *f, int start_y, int end_y);

/*
** Key functions
*/

void					exit_prog(t_fract *f);
void					change_type(t_fract *f);
void					inc_iters(t_fract *f);
void					dec_iters(t_fract *f);

/*
** Fractal calculations
*/

void					*calc_mandelbrot(t_targ *p);
void					*calc_julia(t_targ *p);
void					*calc_ship(t_targ *p);
void					*calc_sierpinski(t_targ *p);
void					*calc_buddha(t_targ *p);
void					*calc_lyapunov(t_targ *p);

#endif
