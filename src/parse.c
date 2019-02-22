/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:39:57 by acarlson          #+#    #+#             */
/*   Updated: 2019/02/21 19:40:12 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int			ft_pedantic_atoi(const char *str)
{
	unsigned int				n;

	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (unsigned char)*str - '0';
		str++;
	}
	if (!!*str)
	{
		ft_dprintf(FT_STDERR_FILENO, "Invalid option: %c\n", *str);
		exit(1);
	}
	return (n);
}

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

t_fract		*get_cmd(int argc, char **argv)
{
	t_fract		*f;
	unsigned	i;

	i = 0;
	DO_IF(!(f = (t_fract *)ft_memalloc(sizeof(t_fract))), exit(1));
	f->height = argc > 1 ? ft_pedantic_atoi(argv[1]) : 1500;
	f->width = argc > 2 ? ft_pedantic_atoi(argv[1]) : 1500;
	DO_IF(argc > 3, WHILE_DO(g_fracts[i] && (strcmp(g_fracts[i], argv[3])), ++i));
	f->arg = argc > 4 ? ft_pedantic_atoi(argv[4]) : 0;
	f->type = !g_fracts[i] ? print_types() : i;
	return (f);
}
