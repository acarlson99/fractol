/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:08:27 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:08:55 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

inline void		toggle_lock(t_fract *f)
{
	if (f->type == Julia)
	{
		f->lock ^= 1;
	}
}
