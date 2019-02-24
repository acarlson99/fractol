/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:38:27 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/23 16:41:03 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** #include <quartz.h>
** CGDirectDisplayID		id = CGMainDisplayID();
** printf("height %d\nwidth %d\n", CGDisplayPixelsHigh(id),\
**									CGDisplayPixelsWide(id));
**
** *****************************************************************************
** #define IDX(X, Y, L, BPP) ((Y) * (L)) + ((X) * ((BPP) / 8))
**
** static void	pixel(t_img *img, t_int2 pos, t_rgba rgba)
** {
**	int32_t	color;
**
**	if (pos.x >= WIN_X || pos.x < 0 || pos.y >= WIN_Y || pos.y < 0)
**		return ;
**	color = 0x00000000;
**	color |= rgba.w << 0x18;
**	color |= rgba.x << 0x10;
**	color |= rgba.y << 0x08;
**	color |= rgba.z << 0x00;
**	*((int32_t*)(&img->buf[IDX(pos.x, pos.y, img->len, img->bpp)])) = color;
** }
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
	[KEY_Q] = exit_prog,
	[KEY_TAB] = change_type,
	[KEY_ESCAPE] = exit_prog,
	[KEY_EQUAL] = inc_iters,
	[KEY_MINUS] = dec_iters,
};

int			key_func(int key, t_fract *f)
{
	(void)f;
	if (g_keycmds[key])
	{
		g_keycmds[key](f);
		return (0);
	}
	ft_printf("Unknown key: %d\n", key);
	return (0);
}

#define IDX(X, Y, L, BPP) ((Y) * (L)) + ((X) * ((BPP) / 8))

int			fract_loop(t_fract *f)
{
	int			i;
	void		*args[NUMBANDS];
	pthread_t	this_thread[NUMBANDS];

	i = 0;
	while (i < f->windowwidth * f->windowheight * (f->bits_per_pixel / 8))
		f->img[i++] = 0;
	i = 0;
	while (i < NUMBANDS)
	{
		args[i] = make_thread_arg(f, (f->windowwidth / NUMBANDS) * i,
								(f->windowwidth / NUMBANDS) * (i + 1));
		if (i + 1 == NUMBANDS)
			((t_targ *)args[i])->end_y = f->windowwidth - 1;
		pthread_create(&this_thread[i], NULL, g_funcs[f->type], args[i]);
		++i;
	}
	i = 0;
	while (i < NUMBANDS)
		pthread_join(this_thread[i++], NULL);
	i = 0;
	while (i < NUMBANDS)
		free(args[i++]);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->mlx_image, 0, 0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fract			*f;

	RET_IF(argc > 5, !!ft_dprintf(FT_STDERR_FILENO, USGMSG));
	f = get_cmd(argc, argv);
	if (!(f->mlx_ptr = mlx_init()))
		exit(1);
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, f->windowwidth,
									f->windowheight, "fractol")))
		exit(1);
	if (!(f->mlx_image = mlx_new_image(f->mlx_ptr, f->windowwidth,\
									f->windowheight)))
		exit(1);
	if (!(f->img = mlx_get_data_addr(f->mlx_image, &f->bits_per_pixel,\
									&f->size_line, &f->endian)))
		exit(1);
	ft_printf("windowheight %u windowwidth %u type %u arg %u\n",\
			f->windowheight, f->windowwidth, f->type, f->arg);
	mlx_loop_hook(f->mlx_ptr, fract_loop, f);
	mlx_key_hook(f->win_ptr, key_func, f);
	mlx_loop(f->mlx_ptr);
}
