/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:10:20 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:10:37 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		change_arg_four(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 4;
	f->save_arg = 1;
}

inline void		change_arg_three(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 3;
	f->save_arg = 1;
}

inline void		change_arg_two(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 2;
	f->save_arg = 1;
}

inline void		change_arg_one(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10 + 1;
	f->save_arg = 1;
}

inline void		change_arg_zero(t_fract *f)
{
	f->tmp_arg = f->tmp_arg * 10;
	f->save_arg = 1;
}
