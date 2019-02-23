/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:14:11 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/22 21:39:34 by acarlson         ###   ########.fr       */
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
	f->update = 0;
}
