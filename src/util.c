/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:21:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/25 23:41:47 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char		*g_msgs[] =
{
	"KEY_Q exit_prog",
	"KEY_TAB change_type",
	"KEY_ESCAPE exit_prog",
	"KEY_EQUAL inc_iters",
	"KEY_MINUS dec_iters",
	"KEY_PAD_ADD inc_iters",
	"KEY_PAD_SUB dec_iters",
	"KEY_RIGHT move_win_right",
	"KEY_LEFT move_win_left",
	"KEY_UP move_win_up",
	"KEY_DOWN move_win_down",
	"KEY_SPACEBAR toggle_text",
	"KEY_L toggle_lock",
	"KEY_ENTER reset_view",
	"KEY_PAD_ENTER reset_view",
	"KEY_R reset_vals",
	"KEY_C toggle_colors",
	"KEY_O rotate_left",
	"KEY_P rotate_right",
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
