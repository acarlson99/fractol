/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:08:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 21:08:08 by acarlson         ###   ########.fr       */
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
	[KEY_0] = reset_vals,
	[KEY_PAD_0] = reset_vals,
	[KEY_C] = toggle_colors,
};

int			key_func(int key, t_fract *f)
{
	(void)f;
	if (key < MAXKEYS && g_keycmds[key])
	{
		g_keycmds[key](f);
		return (0);
	}
	ft_printf("Unknown key: %d\n", key);
	return (0);
}

void		exit_prog(t_fract *f)
{
	(void)f;
	exit(0);
}

void		change_type(t_fract *f)
{
	++f->type;
	f->lock = 0;
	f->update = 1;
	reset_view(f);
}

void		inc_iters(t_fract *f)
{
	if (f->iters < FT_UINT_MAX)
		++f->iters;
	f->update = 1;
}

void		dec_iters(t_fract *f)
{
	if (f->iters)
		--f->iters;
	f->update = 1;
}

void		move_win_right(t_fract *f)
{
	f->center_x -= MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

void		move_win_left(t_fract *f)
{
	f->center_x += MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

void		move_win_up(t_fract *f)
{
	f->center_y += MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

void		move_win_down(t_fract *f)
{
	f->center_y -= MAX(MOVE / f->zoom, 1);
	f->update = 1;
}

void		toggle_text(t_fract *f)
{
	f->display_text ^= 1;
	f->update = 1;
}

void		toggle_lock(t_fract *f)
{
	if (f->type == Julia)
	{
		f->lock ^= 1;
		f->update = 1;
	}
}

void		toggle_colors(t_fract *f)
{
	f->colors ^= 1;
	f->update = 1;
}

void		reset_vals(t_fract *f)
{
	reset_view(f);
	f->iters = 42;
}

void		reset_view(t_fract *f)
{
	f->center_x = f->windowwidth / 2;
	f->center_y = f->windowheight / 2;
	f->zoom = 1;
	f->update = 1;
}

int			close_win(t_fract *f)
{
	(void)f;
	exit(0);
}
