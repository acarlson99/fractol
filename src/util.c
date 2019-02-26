/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:21:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 16:31:00 by acarlson         ###   ########.fr       */
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
	"RET: reset fractal",
	"L: lock mouse (julia only)",
	"C: toggle black/white",
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

int32_t		get_color(unsigned itmax, unsigned i, int color)
{
	if (!color)
	{
		if (itmax == i)
			return (0xFFFFFF);
		return (0);
	}
	else	// TODO: this
	{
		if (itmax == i)
			return (0xFFFFFF);
		return (0);
	}
	return (0);
}
