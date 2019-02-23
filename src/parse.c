/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:39:57 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/22 15:46:36 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int			print_types(void)
{
	unsigned		i;

	ft_printf("Supported fractal options:\n");
	i = 0;
	while (g_fracts[i])
	{
		ft_printf("\t%s\n", g_fracts[i]);
		i++;
	}
	exit(1);
}

static unsigned int			get_num_arg(char *s)
{
	unsigned		n;
	int				m;

	n = 0;
	m = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + *s++ - '0';
		m |= 1;
	}
	if (*s || !m)
		exit(!!ft_dprintf(FT_STDERR_FILENO, "That's not a number, silly\n"));
	return (n);
}

static unsigned int			get_type_arg(char *s)
{
	unsigned		i;

	i = 0;
	DO_IF(g_fracts[i], WHILE_DO(g_fracts[i] && (ft_strcmp(g_fracts[i], s)),
								++i));
	return (!g_fracts[i] ? print_types() : i);
}

static void					check_args(t_fract *f)
{
	if (f->windowwidth > WDMAX || f->windowheight > HTMAX || f->arg > 100)
		exit(!!ft_dprintf(FT_STDERR_FILENO,
						"OwO senpai that's way too big!\n"));
}

t_fract		*get_cmd(int argc, char **argv)
{
	t_fract		*f;
	int			i;
	int			j;

	i = 0;
	j = 0;
	DO_IF(!(f = (t_fract *)ft_memalloc(sizeof(t_fract))), exit(1));
	init_struct(f);
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "w=", 2))
			f->windowwidth = get_num_arg(&argv[i][2]);
		else if (!ft_strncmp(argv[i], "h=", 2))
			f->windowheight = get_num_arg(&argv[i][2]);
		else if (!ft_strncmp(argv[i], "a=", 2))
			f->arg = get_num_arg(&argv[i][2]);
		else if (!ft_strncmp(argv[i], "t=", 2))
			f->type = get_type_arg(&argv[i][2]);
		ELSE_DO(exit(!!ft_dprintf(FT_STDERR_FILENO, USGMSG)));
	}
	check_args(f);
	return (f);
}
