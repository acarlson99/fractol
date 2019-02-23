/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:38:27 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/22 16:45:22 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** #include <quartz.h>
** CGDirectDisplayID		id = CGMainDisplayID();
** printf("height %d\nwidth %d\n", CGDisplayPixelsHigh(id),\
**									CGDisplayPixelsWide(id));
*/

const char					*g_fracts[] =
{
	"mandelbrot",
	"julia",
	"ship",
	"sierpinski",
	"buddha",
	"lyapunov",
	NULL,
};

const t_fnptr				g_funcs[] =
{
	calc_mandelbrot,
	calc_julia,
	calc_ship,
	calc_sierpinski,
	calc_buddha,
	calc_lyapunov,
	NULL,
};

const t_kfun			g_keycmds[MAXKEYS] =
{
	[12] = exit_prog,
	[53] = exit_prog,
};

int			key_func(int key, t_fract *f)
{
	(void)f;
	if (g_keycmds[key])
	{
		g_keycmds[key](f);
		f->update = 1;
		return (0);
	}
	ft_printf("Unknown key: %d\n", key);
	return (0);
}

int			fract_loop(t_fract *f)
{
	(void)f;
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->mlx_image, 0, 0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fract			*f;

	RET_IF(argc > 5, !!ft_dprintf(FT_STDERR_FILENO, USGMSG));
	f = get_cmd(argc, argv);
	if(!(f->mlx_ptr = mlx_init()))
		exit(1);
	if (!(f->mlx_image
			= mlx_new_image(f->mlx_ptr, f->windowwidth, f->windowheight)))
		exit(1);
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, f->windowwidth,
									f->windowheight, "fractol")))
		exit(1);
	ft_printf("windowheight %u windowwidth %u type %u arg %u\n", f->windowheight, f->windowwidth, f->type, f->arg);
	mlx_loop_hook(f->mlx_ptr, fract_loop, f);
	mlx_key_hook(f->win_ptr, key_func, f);
	char *a = f->mlx_image;
	a[100] = 100;
	mlx_loop(f->mlx_ptr);
}
