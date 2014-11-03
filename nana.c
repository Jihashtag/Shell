/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nana.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:46:39 by jbert             #+#    #+#             */
/*   Updated: 2014/06/20 20:39:52 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	dup_tb(char ***argv, char ***av, int i, int *ac)
{
	i = (*ac);
	while (((*argv)[i - 1] || i == 0) && (*argv)[i] && (*argv)[i][0] != ';' && \
			(*argv)[i][0] != '|' && (*argv)[i][0] != '>' && \
			(*argv)[i][0] != '<' && (*argv)[i][0] != '&')
		i++;
	(*av) = (char **)ft_memalloc(sizeof(char *) * (i - (*ac) + 2));
	i = 0;
	while (((*argv)[(*ac) - 1] || (i == 0)) && (*argv)[(*ac)] && \
			(*argv)[(*ac)][0] != ';' && (*argv)[(*ac)][0] != '|' && \
			(*argv)[(*ac)][0] != '&' && (*argv)[(*ac)][0] != '>' && \
			(*argv)[(*ac)][0] != '<')
	{
		(*av)[i] = ft_strdup((*argv)[(*ac)]);
		i++;
		(*ac)++;
	}
	(*av)[i] = NULL;
	(*av)[i + 1] = 0;
}

void	retab(int *save, int *p, int i)
{
	if (i == 1)
	{
		dup2(save[1], 1);
		dup2(p[0], 0);
		close(p[0]);
		return ;
	}
	if (i == 0)
	{
		dup2(save[1], 1);
		dup2(save[0], 0);
		return ;
	}
	if (i == 2)
	{
		pipe(p);
		dup2(p[1], 1);
		close(p[1]);
		return ;
	}
}

void	ft_start(char *flag, int *save, int *p)
{
	if (flag[0] == '>' || flag[0] == '<' || flag[1] == '|')
		retab(save, p, 0);
	if (flag[0] == '|')
		retab(save, p, 1);
	flag[1] = flag[0];
	flag[0] = 0;
}

int		love(char **argv)
{
	int	a;

	a = 0;
	while (argv[a++] && argv[a])
	{
		ft_free(argv[0]);
		argv[0] = ft_strdup(argv[a]);
		if (CMP("love", "t'aime"))
			ft_printf("oh\n");
		else if (CMP("you", "toi"))
			ft_printf("Me too\n");
		else
			break ;
	}
	return (0);
}

void	save_hist(char **env, char *l, int i)
{
	static char	*argv[2];
	static int	fd = 0;

	if (!fd)
	{
		argv[0] = ft_strdup("~/.42shistory");
		argv[1] = NULL;
		ft_tild(argv, env);
		fd = open(argv[0], O_RDWR | O_CREAT, S_IRWXU);
		if (fd > 0)
		{
			while (read(fd, argv[0], BUFF_SIZE))
				;
		}
	}
	if (fd > 0)
	{
		if (i && l && (ft_strlen(l) > 2 || l[0] != ' '))
			ft_putendl_fd(l, fd);
	}
}
