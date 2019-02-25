/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:38:27 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/24 16:13:53 by acarlson         ###   ########.fr       */
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

static const t_fnptr				g_funcs[] =
{
	calc_mandelbrot,
	calc_julia,
	calc_ship,
	calc_sierpinski,
	calc_buddha,
	calc_lyapunov,
	NULL,
};

static void		check_stuff(t_fract *f)
{
	int		i;
	
	i = 0;
	while (i < f->windowwidth * f->windowheight * (f->bits_per_pixel / 8))
		f->img[i++] = 0;
	if (!g_funcs[f->type])
		f->type = 0;
}

static int			fract_loop(t_fract *f)
{
	int			i;
	void		*args[NUMBANDS];
	pthread_t	thread_ids[NUMBANDS];

	if (!f->update || (f->lock && f->type == Julia))
		return (0);
	check_stuff(f);
	i = -1;
	while (++i < NUMBANDS)
	{
		args[i] = make_thread_arg(f, (f->windowwidth / NUMBANDS) * i,
								  (f->windowwidth / NUMBANDS) * (i + 1));
		if (i + 1 == NUMBANDS)
			((t_targ *)args[i])->end_y = f->windowwidth - 1;
		pthread_create(&thread_ids[i], NULL, g_funcs[f->type], args[i]);
	}
	i = 0;
	while (i < NUMBANDS)
		pthread_join(thread_ids[i++], NULL);
	i = 0;
	while (i < NUMBANDS)
		free(args[i++]);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->mlx_image, 0, 0);
	if (f->display_text)
		display_text(f);
	f->update = 0;
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
	mlx_loop_hook(f->mlx_ptr, fract_loop, f);
	mlx_key_hook(f->win_ptr, key_func, f);
	mlx_mouse_hook(f->win_ptr, mouse_func, f);
	mlx_loop(f->mlx_ptr);
}
