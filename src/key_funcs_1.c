/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:07:18 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/26 18:08:16 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		exit_prog(t_fract *f)
{
	(void)f;
	exit(0);
}

inline void		change_type(t_fract *f)
{
	int			i;

	i = 0;
	if (f->tmp_arg > 0)
	{
		while (i < f->tmp_arg)
		{
			++f->type;
			++i;
		}
		reset_register(f);
	}
	else
		++f->type;
	f->lock = 0;
	f->update = 1;
	reset_view(f);
}

inline void		inc_iters(t_fract *f)
{
	if (f->tmp_arg > 0)
	{
		f->iters = f->tmp_arg;
		reset_register(f);
	}
	else if (f->iters < FT_UINT_MAX)
		++f->iters;
	f->update = 1;
}

inline void		dec_iters(t_fract *f)
{
	if (f->tmp_arg > 0)
	{
		f->iters = f->tmp_arg;
		reset_register(f);
	}
	else if (f->iters)
		--f->iters;
	f->update = 1;
}

inline void		toggle_text(t_fract *f)
{
	f->display_text ^= 1;
	f->update = 1;
}
