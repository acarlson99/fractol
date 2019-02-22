/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:38:27 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/21 19:40:13 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** #include <quartz.h>
** CGDirectDisplayID		id = CGMainDisplayID();
** printf("height %d\nwidth %d\n", CGDisplayPixelsHigh(id),\
**									CGDisplayPixelsWide(id));
*/

char			*g_fracts[] =
{
	"mandelbrot",
	"julia",
	"ship",
	"sierpinski",
	"buddha",
	"lyapunov",
	NULL,
};

t_fnptr			g_funcs[] =
{
	calc_mandelbrot,
	calc_julia,
	calc_ship,
	calc_sierpinski,
	calc_buddha,
	calc_lyapunov,
	NULL,
};

int			main(int argc, char **argv)
{
	t_fract			*f;

	RET_IF(argc > 5, !!ft_dprintf(FT_STDERR_FILENO, USGMSG));
	f = get_cmd(argc, argv);
	ft_printf("height %u width %u type %u arg %u\n", f->height, f->width, f->type, f->arg);
}
