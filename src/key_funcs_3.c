/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:09:08 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:09:26 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
