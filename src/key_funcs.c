/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:08:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 15:21:14 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const t_kfun			g_keycmds[MAXKEYS] =
{
	[KEY_Q] = exit_prog,
	[KEY_TAB] = change_type,
	[KEY_ESCAPE] = exit_prog,
	[KEY_EQUAL] = inc_iters,
	[KEY_MINUS] = dec_iters,
	[KEY_PAD_ADD] = inc_iters,
	[KEY_PAD_SUB] = dec_iters,
	[KEY_RIGHT] = move_win_right,
	[KEY_LEFT] = move_win_left,
	[KEY_UP] = move_win_up,
	[KEY_DOWN] = move_win_down,
	[KEY_SPACEBAR] = toggle_text,
	[KEY_L] = toggle_lock,
	[KEY_ENTER] = reset_view,
	[KEY_PAD_ENTER] = reset_view,
	[KEY_R] = reset_vals,
	[KEY_C] = toggle_colors,
	[KEY_OPEN_BRACE] = rotate_left,
	[KEY_CLOSE_BRACE] = rotate_right,

	[KEY_PAD_0] = change_arg_zero,
	[KEY_PAD_1] = change_arg_one,
	[KEY_PAD_2] = change_arg_two,
	[KEY_PAD_3] = change_arg_three,
	[KEY_PAD_4] = change_arg_four,
	[KEY_PAD_5] = change_arg_five,
	[KEY_PAD_6] = change_arg_six,
	[KEY_PAD_7] = change_arg_seven,
	[KEY_PAD_8] = change_arg_eight,
	[KEY_PAD_9] = change_arg_nine,

	[KEY_0] = change_arg_zero,
	[KEY_1] = change_arg_one,
	[KEY_2] = change_arg_two,
	[KEY_3] = change_arg_three,
	[KEY_4] = change_arg_four,
	[KEY_5] = change_arg_five,
	[KEY_6] = change_arg_six,
	[KEY_7] = change_arg_seven,
	[KEY_8] = change_arg_eight,
	[KEY_9] = change_arg_nine,

	[KEY_E] = evaluate_arg,
	[KEY_DEL] = reset_register,

	[KEY_M] = reload_register,
};

inline void		reload_register(t_fract *f)
{
	f->tmp_arg = f->saved_arg;
}

inline void		reset_register(t_fract *f)
{
	f->saved_arg = f->tmp_arg;
	f->tmp_arg = 0;
}

inline void		evaluate_arg(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->arg = f->tmp_arg;
		reset_register(f);
		f->update = 1;
	}
}

inline void		change_arg_nine(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 9;
}

inline void		change_arg_eight(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 8;
}

inline void		change_arg_seven(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 7;
}

inline void		change_arg_six(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 6;
}

inline void		change_arg_five(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 5;
}

inline void		change_arg_four(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 4;
}

inline void		change_arg_three(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 3;
}

inline void		change_arg_two(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 2;
}

inline void		change_arg_one(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 1;
}

inline void		change_arg_zero(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10;
}

int				key_func(int key, t_fract *f)
{
	if (key < MAXKEYS && g_keycmds[key])
	{
		g_keycmds[key](f);
		return (0);
	}
	if (!f->save_arg)
		f->tmp_arg = 0;
	ft_printf("Unknown key: %d\n", key);
	return (0);
}

inline void		exit_prog(t_fract *f)
{
	(void)f;
	exit(0);
}

inline void		change_type(t_fract *f)
{
	unsigned		i;

	i = 0;
	if (f->tmp_arg)
	{
		while (i < f->tmp_arg)
		{
			++f->type;
			++i;
		}
		reset_register(f);
	}
	else
		++f->type;
	f->lock = 0;
	f->update = 1;
	reset_view(f);
}

inline void		inc_iters(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->iters = f->tmp_arg;
		reset_register(f);
	}
	else if (f->iters < FT_UINT_MAX)
		++f->iters;
	f->update = 1;
}

inline void		dec_iters(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->iters = f->tmp_arg;
		reset_register(f);
	}
	else if (f->iters)
		--f->iters;
	f->update = 1;
}

inline void		move_win_right(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->center_x -= f->tmp_arg;
		reset_register(f);
	}
	else
		f->center_x -= MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

inline void		move_win_left(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->center_x += f->tmp_arg;
		reset_register(f);
	}
	else
		f->center_x += MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

inline void		move_win_up(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->center_y += f->tmp_arg;
		reset_register(f);
	}
	else
		f->center_y += MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

inline void		move_win_down(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->center_y -= f->tmp_arg;
		reset_register(f);
	}
	else
		f->center_y -= MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

inline void		toggle_text(t_fract *f)
{
	f->display_text ^= 1;
	f->update = 1;
}

inline void		toggle_lock(t_fract *f)
{
	if (f->type == Julia)
	{
		f->lock ^= 1;
		f->update = 1;
	}
}

inline void		toggle_colors(t_fract *f)
{
	f->colors ^= 1;
	f->update = 1;
}

inline void		reset_vals(t_fract *f)
{
	reset_view(f);
	f->rot = 0;
	f->tmp_arg = 0;
	f->saved_arg = 0;
	f->lock = 0;
	f->iters = ITERS;
}

inline void		reset_view(t_fract *f)
{
	f->center_x = f->windowwidth / 2;
	f->center_y = f->windowheight / 2;
	f->zoom = 1;
	f->update = 1;
}

int				close_win(t_fract *f)
{
	(void)f;
	exit(0);
}

/*
** Rotates int to make pretty colors
*/

inline void		rotate_left(t_fract *f)
{
	++f->rot;
	f->update = 1;
}

inline void		rotate_right(t_fract *f)
{
	--f->rot;
	f->update = 1;
}
