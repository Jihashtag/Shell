/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 12:45:09 by jbert             #+#    #+#             */
/*   Updated: 2014/06/24 18:47:51 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		up(char **arg, int *k, int j, int *i)
{
	if ((*k) > 0)
		(*k)--;
	if ((*k) == 0)
	{
		while (arg[*k + 1] != NULL)
			(*k)++;
	}
	while (arg[*k][j] != '\n' && arg[*k][j] != '\0')
		j++;
	if (arg[*k][j] == '\n')
		arg[*k][j] = '\0';
	(*i) = j;
	return (j);
}

int		left(char **arg, int *i, int *k)
{
	if ((*i) > 0)
		(*i)--;
	else
		(*i) = ft_strlen(arg[*k]);
	return (1);
}

int		right(int j, char **arg, int *i, int *k)
{
	j = ft_strlen(arg[*k]);
	if ((*i) < j && (j = 1))
		(*i)++;
	else
		(*i) = 0;
	return (j);
}

char	**get_path(char **env)
{
	int		i;
	int		fd;
	char	buf[1025];

	ft_bzero(buf, sizeof(char) * 1025);
	fd = open("/etc/paths", O_RDONLY);
	if (fd <= 0 && ft_putendl_fd("Unknown error", 2))
		exit(-1);
	read(fd, buf, 1024);
	close(fd);
	fd = 0;
	while (buf[fd])
	{
		if (buf[fd] == '\n')
			buf[fd] = ':';
		fd++;
	}
	i = indexinenv("PATH", env);
	tb_realloc(&env, 0);
	env[i] = ft_strjoin("PATH=", buf);
	env[i + 1] = NULL;
	return (env);
}

char	**have_to_go(char **env)
{
	if (!env || env[0] == NULL)
	{
		ft_putstr_fd("No env, Leaving", 2);
		exit(-1);
	}
	if (!env[indexinenv("PATH", env)])
	{
		ft_putstr_fd("No PATH\n", 2);
		env = get_path(env);
	}
	return (env);
}
