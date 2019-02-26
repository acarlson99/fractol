/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:29:22 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 23:33:06 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>
# include "mlx_keys_macos.h"
# include "mlx.h"
# include "libft.h"

# define USGMSG "usage: ./fractol [at]=arg\n"
# define HTMAX 10000
# define WDMAX 10000
# define DEFAULTHEIGHT 1000
# define DEFAULTWIDTH 1000
# define NUMBANDS 16
# define MOVE 10
# define ZOOM 20
# define ITERS 42

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

enum	e_types {
	Mandelbrot,
	Julia,
	Ship,
	Sierpinski,
	Buddha,
	Lyapunov,
};

typedef struct			s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_image;
	char			*img;

	int				windowheight;
	int				windowwidth;

	int				move_x;
	int				move_y;

	int				center_x;
	int				center_y;
	double			zoom;

	enum e_types	type;
	unsigned		arg;
	unsigned		tmp_arg;
	unsigned		saved_arg;
	int				save_arg;

	unsigned		iters;

	int				mouse_x;
	int				mouse_y;
	t_vect3			*c;

	int				bits_per_pixel;
	int				size_line;
	int				endian;

	int				update;
	int				display_text;

	int				lock;

	int				colors;

	int				rot;
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
** Arg parsing
*/

t_fract					*get_cmd(int argc, char **argv);

/*
** Display
*/

void					display_text(t_fract *f);

/*
** Struct manipulation
*/

void					init_struct(t_fract *f);
void					*make_thread_arg(t_fract *f, int start_y, int end_y);
t_vect3					*scale_point(t_fract *f, int x, int y);

/*
** Key functions
*/

int						key_func(int key, t_fract *f);
void					exit_prog(t_fract *f);
void					change_type(t_fract *f);
void					inc_iters(t_fract *f);
void					dec_iters(t_fract *f);
void					move_win_right(t_fract *f);
void					move_win_left(t_fract *f);
void					move_win_up(t_fract *f);
void					move_win_down(t_fract *f);
void					toggle_text(t_fract *f);
void					toggle_lock(t_fract *f);
void					toggle_colors(t_fract *f);
void					reset_vals(t_fract *f);
void					reset_view(t_fract *f);
void					rotate_left(t_fract *f);
void					rotate_right(t_fract *f);

void					change_arg_zero(t_fract *f);
void					change_arg_one(t_fract *f);
void					change_arg_two(t_fract *f);
void					change_arg_three(t_fract *f);
void					change_arg_four(t_fract *f);
void					change_arg_five(t_fract *f);
void					change_arg_six(t_fract *f);
void					change_arg_seven(t_fract *f);
void					change_arg_eight(t_fract *f);
void					change_arg_nine(t_fract *f);
void					evaluate_arg(t_fract *f);
void					reset_register(t_fract *f);
void					reload_register(t_fract *f);

/*
** Mouse functions
*/

int						mouse_func(int b, int x, int y, t_fract *f);
void					zoom_in(t_fract *f, int b, int x, int y);
void					zoom_out(t_fract *f, int b, int x, int y);
int						mouse_move(int x, int y, t_fract *f);
int						close_win(t_fract *f);

/*
** Fractal calculations
*/

int32_t					get_color(unsigned itmax,\
									unsigned i, int color, int rot);
void					*calc_mandelbrot(t_targ *p);
void					*calc_julia(t_targ *p);
void					*calc_ship(t_targ *p);
void					*calc_sierpinski(t_targ *p);
void					*calc_buddha(t_targ *p);
void					*calc_lyapunov(t_targ *p);

#endif
