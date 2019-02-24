/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:14:11 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 15:35:54 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_struct(t_fract *f)
{
	f->mlx_ptr = NULL;
	f->win_ptr = NULL;
	f->mlx_image = NULL;
	f->windowheight = DEFAULTHEIGHT;
	f->windowwidth = DEFAULTWIDTH;
	f->type = 0;
	f->arg = 0;
	f->iters = 10;
	f->update = 0;
}

void			*make_thread_arg(t_fract *f, int start_y, int end_y)
{
	t_targ		*ptr;

	if (!(ptr = malloc(sizeof(t_targ))))
		exit(1);
	ptr->f = f;
	ptr->start_y = start_y;
	ptr->end_y = end_y;
	return (ptr);
}
