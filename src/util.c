/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:21:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 22:08:46 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char		*g_msgs[] =
{
	"SPACE: toggle messages",
	"TAB: switch fractal",
	"ESC/Q: quit",
	"Arrows: move",
	"+/-: inc/dec iterations",
	"RET: reset view",
	"0: reset fractal",
	"L: lock mouse (julia only)",
	"C: toggle black/white",
	"R: increase color offset",
	"T: decrease color offset",
	NULL,
};

void		display_text(t_fract *f)
{
	unsigned		i;

	i = 0;
	while (g_msgs[i])
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
		return (((c << rot)|(c >> (32 - rot))) & 0xFFFFFF);
	}
	else
	{
		if (itmax == i)
			return (0xFFFFFF);
		return (0);
	}
	return (0);
}
