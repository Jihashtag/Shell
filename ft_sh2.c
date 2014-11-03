/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 16:04:25 by jbert             #+#    #+#             */
/*   Updated: 2014/06/25 17:38:40 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		trash_bin(char **av, int *ac, char **env, char **els)
{
	static int	j = 0;
	int			other;
	int			i;

	if (env)
	{
		if ((els[(*ac)] && els[(*ac) + 1]) || (j == 1 && (j = 0) == 0))
			(*ac)++;
		else
			j = 1;
		i = treat_prog(av, env);
		free_tb(av, 0, 0, 1);
		return (i);
	}
	else
	{
		other = open(av[++(*ac)], O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
		if (!av[(*ac) + 1])
			(*ac)++;
		dup2(other, 1);
		close(other);
	}
	return (0);
}

void	or_pipe(char **argv, char *flag, int *ac)
{
	if (flag[3] == 1)
	{
		if (argv[(*ac)] && argv[(*ac)][0] == '|')
		{
			if (flag[2] == 0)
			{
				while (argv[(*ac)] && argv[(*ac)][0] != ';' \
						&& argv[(*ac)][0] != '&')
					(*ac)++;
			}
		}
		else
		{
			ft_putstr_fd("Parse error near :", 2);
			ft_putchar_fd(argv[(*ac)][0], 2);
			ft_putchar_fd('\n', 2);
			while (argv[(*ac)] && argv[(*ac)][0] != ';')
				(*ac)++;
		}
		flag[3] = 0;
	}
}

void	and_ep(char **argv, char *flag, int *ac)
{
	if (flag[1] == '&')
	{
		if ((argv[(*ac)][0] != '&' || flag[2] != 0))
		{
			if (argv[(*ac)][0] != '&')
			{
				ft_putstr_fd("Parse error near :", 2);
				ft_putchar_fd(argv[(*ac) - 1][0], 2);
				ft_putchar_fd('\n', 2);
			}
			while (argv[(*ac)] && argv[(*ac)][0] != ';')
			{
				if (argv[(*ac) - 1][0] == '|' && argv[(*ac)][0] != '|')
					break ;
				(*ac)++;
			}
		}
		if (argv[(*ac)])
			(*ac)++;
	}
}

void	init_all(int *ac, char flag[4], int save[2])
{
	(*ac) = 0;
	flag[0] = -1;
	flag[3] = 0;
	flag[1] = 0;
	flag[2] = 0;
	save[1] = dup(1);
	save[0] = dup(0);
}

int		pre_treat(char **argv, char **env, int ac, char **av)
{
	char	flag[4];
	int		p[2];
	int		save[2];

	env = have_to_go(env);
	init_all(&ac, flag, save);
	while (argv[ac] && flag[0] != 0)
	{
		ft_start(flag, save, p);
		or_pipe(argv, flag, &ac);
		and_ep(argv, flag, &ac);
		norme_one(&argv, &ac, &av, flag);
		norme_last(flag, &ac, argv);
		if (flag[0] == '|')
		{
			if (norme_two(&argv, &ac, flag))
				retab(save, p, 2);
			else
				flag[3] = 1;
		}
		flag[2] = trash_bin(av, &ac, env, argv);
	}
	ft_start(flag, save, p);
	return (0);
}
