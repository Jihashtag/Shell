/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 22:54:46 by jbert             #+#    #+#             */
/*   Updated: 2014/06/24 18:42:34 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_env(char **env)
{
	int	i;

	i = indexinenv("SHELL", env);
	if (env[i])
		env[i] = ft_strdup("SHELL=42sh");
	i = 0;
	while (env[i])
	{
		if (env[i][0])
			ft_putendl(env[i]);
		i++;
	}
}

void	writor(char **argv)
{
	int		fd;
	int		a;
	char	wrote[EDITOR + 1];

	ft_printf("You can write %d characters per line\n", EDITOR);
	if (!argv[1])
		return ;
	if (!argv[1][0])
		return ;
	a = 1;
	fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	while (fd > 1 && ft_strcmp(wrote, "quit\n") && (a != 0))
	{
		ft_bzero(wrote, sizeof(char) * (EDITOR + 1));
		a = read(0, wrote, EDITOR);
		if (ft_strcmp(wrote, "quit\n"))
		{
			write(1, wrote, ft_strlen(wrote));
			write(fd, wrote, ft_strlen(wrote));
		}
	}
	close(fd);
	ft_printf("Quit\n");
}

int		indexinenv(char *wut, char **env)
{
	int			i;
	static char	*s = 0;
	int			j;

	j = 0;
	while (wut[j] && wut[j] != '=')
		j++;
	i = 0;
	while (env && env[i] && (ft_strncmp(env[i], wut, j - 1) \
				|| env[i][j] != '='))
		i++;
	if (env && !env[i])
	{
		if (!s || (s && ft_strcmp(s, wut)))
		{
			if (s)
				ft_free(s);
			s = ft_strdup(wut);
			ft_putstr_fd(wut, 2);
			ft_putendl_fd(": not in env", 2);
		}
	}
	return (i);
}

char	**old_path(char *wut, char **env)
{
	char				*now;
	unsigned int		i;
	unsigned int		j;

	i = indexinenv(wut, env);
	if (!env[i])
	{
		tb_realloc(&env, 0);
		env[i] = ft_strjoin(wut, "=");
		env[i + 1] = NULL;
	}
	env[i][ft_strlen(wut) + 1] = '\0';
	now = (char *)ft_memalloc(sizeof(char) * 2049);
	ft_bzero(now, sizeof(char) * 2049);
	now = getcwd(now, 2048);
	j = ft_strlen(now);
	if (j > (ft_strlen(wut) + 1))
		now[j] = '/';
	now[j + 1] = '\0';
	env[i] = ft_strjoin(env[i], now);
	if (now)
		ft_free(now);
	return (env);
}

void	tild(char **env, char **argv, int j)
{
	int			i;
	int			index;
	char		*temp;

	i = 0;
	index = indexinenv("HOME", env);
	argv[j]++;
	temp = ft_strdup(argv[j]--);
	if (!env[index] && ((argv[j] = ft_strjoin("/home", temp)) || \
		(argv[j][0] != '/' && ft_putendl_fd("Unkown error", 2))) && temp)
		return (ft_free(temp));
	if (argv[j])
		ft_free(argv[j]);
	argv[j] = (char *)ft_memalloc(sizeof(char) * (POO));
	ft_bzero(argv[j], sizeof(char) * (POO));
	i = 5;
	while (env[index][i])
	{
		argv[j][i - 5] = env[index][i];
		i++;
	}
	argv[j][i - 5] = '/';
	ft_strcat(argv[j], temp);
	if (temp)
		ft_free(temp);
}
