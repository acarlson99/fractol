/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:11:04 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:11:08 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		change_arg_nine(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 9;
	f->save_arg = 1;
}

inline void		change_arg_eight(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 8;
	f->save_arg = 1;
}

inline void		change_arg_seven(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 7;
	f->save_arg = 1;
}

inline void		change_arg_six(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 6;
	f->save_arg = 1;
}

inline void		change_arg_five(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 5;
	f->save_arg = 1;
}
