/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:46:40 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 20:41:37 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const t_kfun			g_funcs[10] =
{
	[4] = zoom_in,
	[5] = zoom_out,
	[6] = move_win_left,
	[7] = move_win_right,
	NULL,
};

int			mouse_func(int b, int x, int y, t_fract *f)
{
	if (g_funcs[b])
		g_funcs[b](f, b, x, y);
	else
		ft_printf("%d not supported\n", b);
	return (0);
}

void		zoom_in(t_fract *f, int b, int x, int y)
{
	(void)b;
	(void)x;
	(void)y;
	(void)f;
	ft_printf("%d %d %d\n", b, x, y);
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
	ft_printf("%d %d %d\n", b, x, y);
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
	ft_printf("MOVE %d %d\n", x, y);
	return (0);
}
