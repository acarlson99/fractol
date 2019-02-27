/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:21:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 19:21:53 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char		*g_msgs[] =
{
	"Q/Esc: kill program",
	"Space: toggle text",
	"Ret: reset view",
	"R: reset values",
	"C: toggle colors",
	"0-9: integer argument",
	"N: make argument negative",
	"E: evaluate arg (Mandelbrot/Julia)",
	"L: lock mouse (Julia only)",
	"Del: reset integer argument",
	"M: reload last integer argument",
	"Tab: cycle fractals",
	"+/-: inc/dec iters",
	"Arrow keys: move around",
	"Scroll: zoom in/out",
	"[/]: change palette",
};

void		display_text(t_fract *f)
{
	unsigned		i;

	i = 0;
	while (i < sizeof(g_msgs) / sizeof(*g_msgs))
	{
		mlx_string_put(f->mlx_ptr, f->win_ptr, 4,
					i * 16, FT_INT_MAX, (char *)g_msgs[i]);
		++i;
	}
}

int32_t		get_color(unsigned itmax, unsigned i, int color, int rot)
{
	int32_t		c;

	if (color)
	{
		c = (i * itmax & 0xFFFFFF);
		return (((c << rot) | (c >> (32 - rot))) & 0xFFFFFF);
	}
	else
	{
		if (itmax == i)
			return (0xFFFFFF);
		return (0);
	}
	return (0);
}
