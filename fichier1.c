/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 22:54:24 by jbert             #+#    #+#             */
/*   Updated: 2014/06/23 19:22:00 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		tb_cpy(char ***tb, char **tmp, int j, int k)
{
	int			i;
	int			l;

	i = 0;
	while (i < j && tmp[i])
	{
		(*tb)[i] = ft_strdup(tmp[i]);
		i++;
	}
	(*tb)[i] = NULL;
	l = i;
	while (--l >= 0)
	{
		if (k)
			ft_free(tmp[l]);
		tmp[l] = NULL;
	}
	if (k)
		ft_free(tmp);
	tmp = NULL;
	return (i);
}

int		tb_realloc(char ***tb, int k)
{
	char	**tmp;
	int		i;
	int		j;

	if (!(*tb))
	{
		(*tb) = (char **)ft_memalloc(sizeof(char) * 2);
		(*tb)[0] = NULL;
		(*tb)[1] = NULL;
		return (1);
	}
	j = 0;
	while ((*tb)[j])
		j++;
	tmp = (char **)ft_memalloc(sizeof(char *) * (j + 1));
	i = tb_cpy(&tmp, *tb, j, k);
	(*tb) = (char **)ft_memalloc(sizeof(char *) * (j + 2));
	i = tb_cpy(tb, tmp, j, 1);
	(*tb)[i] = NULL;
	(*tb)[i + 1] = NULL;
	return (i);
}

char	**envnmt(char **argv, char ***env)
{
	int			i;
	char		*tmp;

	if (!argv[1])
		return (*env);
	if (!argv[1][0])
		return (*env);
	tmp = ft_strjoin(argv[1], "=");
	if ((i = indexinenv(argv[1], *env)) && !ft_strcmp(argv[0], "setenv"))
	{
		if (!(*env)[i] && tb_realloc(env, 0))
			(*env)[i + 1] = NULL;
		(*env)[i] = ft_strjoin(tmp, argv[2]);
	}
	else if (!ft_strcmp(argv[0], "unsetenv") && (*env)[i])
	{
		if (!ft_strcmp(argv[1], "PATH"))
			ft_putendl_fd("You can't delete PATH", 2);
		else
			(*env)[i][0] = '\0';
	}
	if (tmp)
		ft_free(tmp);
	return (*env);
}

int		execute(char **argv, char *temp, char **env)
{
	int		fd;
	pid_t	ls;

	if (access(temp, X_OK) == 0)
	{
		prog(1);
		ls = fork();
		if (ls > 0)
		{
			fd = 0;
			waitpid(ls, &fd, WUNTRACED);
			prog(0);
			return (fd);
		}
		if (ls == 0)
		{
			execve(temp, argv, env);
			ft_putstr_fd("ERROR ", 2);
			exit(-1);
		}
	}
	return (1);
}

int		other(char **argv, char **env)
{
	int		a;
	char	*temp;
	char	**cp;
	char	*tmp;

	a = 1;
	if (!ft_strchr(argv[0], '/') && (temp = ft_strdup("\0")))
	{
		cp = ft_strsplit2(env[indexinenv("PATH", env)], ':');
		while (cp[a] && cp[a][0])
		{
			ft_free(temp);
			tmp = ft_strjoin(cp[a], "/");
			temp = ft_strjoin(tmp, argv[0]);
			ft_free(tmp);
			a++;
			if ((execute(argv, temp, env) == 0 && (a = -1)) || !cp[a])
				break ;
		}
		ft_free(temp);
		free_tb(cp, 0, 0, 1);
	}
	else if (execute(argv, argv[0], env) == 0)
		return (1);
	return (a * -1);
}
