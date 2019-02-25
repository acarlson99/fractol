/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:21:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/24 15:33:37 by acarlson         ###   ########.fr       */
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
