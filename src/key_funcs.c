/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:08:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:11:37 by acarlson         ###   ########.fr       */
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
	[KEY_R] = reset_vals,
	[KEY_C] = toggle_colors,
	[KEY_OPEN_BRACE] = rotate_left,
	[KEY_CLOSE_BRACE] = rotate_right,
	[KEY_PAD_0] = change_arg_zero,
	[KEY_PAD_1] = change_arg_one,
	[KEY_PAD_2] = change_arg_two,
	[KEY_PAD_3] = change_arg_three,
	[KEY_PAD_4] = change_arg_four,
	[KEY_PAD_5] = change_arg_five,
	[KEY_PAD_6] = change_arg_six,
	[KEY_PAD_7] = change_arg_seven,
	[KEY_PAD_8] = change_arg_eight,
	[KEY_PAD_9] = change_arg_nine,
	[KEY_0] = change_arg_zero,
	[KEY_1] = change_arg_one,
	[KEY_2] = change_arg_two,
	[KEY_3] = change_arg_three,
	[KEY_4] = change_arg_four,
	[KEY_5] = change_arg_five,
	[KEY_6] = change_arg_six,
	[KEY_7] = change_arg_seven,
	[KEY_8] = change_arg_eight,
	[KEY_9] = change_arg_nine,
	[KEY_E] = evaluate_arg,
	[KEY_DEL] = reset_register,
	[KEY_M] = reload_register,
	[KEY_N] = pos_neg,
};

int				key_func(int key, t_fract *f)
{
	if (key < MAXKEYS && g_keycmds[key])
	{
		g_keycmds[key](f);
		if (!f->save_arg)
			f->tmp_arg = 0;
		f->save_arg = 0;
		return (0);
	}
	return (0);
}
