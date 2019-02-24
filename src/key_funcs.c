/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:08:42 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 16:43:24 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		exit_prog(t_fract *f)
{
	(void)f;
	exit(0);
}

void		change_type(t_fract *f)
{
	++f->type;
	if (!g_fracts[f->type])
		f->type = 0;
	f->update = 1;
}

void		inc_iters(t_fract *f)
{
	++f->iters;
}

void		dec_iters(t_fract *f)
{
	if (f->iters)
		--f->iters;
}
