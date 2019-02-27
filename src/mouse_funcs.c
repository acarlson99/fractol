/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:46:40 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:15:39 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const t_kfun			g_funcs[10] =
{
	[SCROLL_UP] = zoom_in,
	[SCROLL_DOWN] = zoom_out,
	[SCROLL_LEFT] = move_win_left,
	[SCROLL_RIGHT] = move_win_right,
};

int			mouse_func(int b, int x, int y, t_fract *f)
{
	if ((unsigned)b < sizeof(g_funcs) / sizeof(*g_funcs) && g_funcs[b])
		g_funcs[b](f, b, x, y);
	return (0);
}

void		zoom_in(t_fract *f, int b, int x, int y)
{
	(void)b;
	(void)x;
	(void)y;
	(void)f;
	if (f->zoom <= 1)
		f->zoom *= 2;
	else
		f->zoom += ZOOM;
	f->update = 1;
}

void		zoom_out(t_fract *f, int b, int x, int y)
{
	(void)b;
	(void)x;
	(void)y;
	(void)f;
	if (f->zoom - ZOOM <= 1)
		f->zoom /= 2;
	else
		f->zoom -= ZOOM;
	f->update = 1;
}

int			mouse_move(int x, int y, t_fract *f)
{
	if (f->lock || f->type != Julia)
		return (0);
	f->mouse_x = x;
	f->mouse_y = y;
	f->update = 1;
	return (0);
}
