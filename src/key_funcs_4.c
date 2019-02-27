/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:11:22 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:12:38 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		pos_neg(t_fract *f)
{
	f->save_arg = 1;
	f->tmp_arg *= -1;
}

inline void		reload_register(t_fract *f)
{
	f->tmp_arg = f->saved_arg;
}

inline void		reset_register(t_fract *f)
{
	f->saved_arg = f->tmp_arg;
	f->tmp_arg = 0;
}

inline void		evaluate_arg(t_fract *f)
{
	if (f->tmp_arg)
	{
		f->arg = f->tmp_arg;
		reset_register(f);
		f->update = 1;
	}
}

inline void		toggle_colors(t_fract *f)
{
	f->colors ^= 1;
	f->update = 1;
}
