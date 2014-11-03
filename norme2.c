/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 18:53:55 by jbert             #+#    #+#             */
/*   Updated: 2014/06/25 17:17:48 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		change_dir(char **argv, char **env)
{
	if (chdir(argv[1]) == 0)
	{
		env = old_path("PWD", env);
		save_env(env, 1);
		return (0);
	}
	else
		return (ft_putstr_fd("Error\n", 2));
}

int		ft_cd(char **argv, char **env)
{
	DIR *d;

	if (!(argv[1]) || (argv[1] && (!argv[1][0] || \
					(argv[1][0] == '-' && argv[1][1] == '-'))))
	{
		argv[1] = ft_strdup("~");
		argv[2] = NULL;
	}
	else if (argv[1][0] == '-' && argv[1][1] == '\0')
	{
		argv[1] = ft_strdup(ft_envsearch("OLDPWD=", &env));
		ft_putendl(argv[1]);
	}
	env = old_path("OLDPWD", env);
	if (argv[1][0] == '~')
		tild(env, argv, 1);
	if ((d = opendir(argv[1])) && !closedir(d))
		return (change_dir(argv, env));
	else
		return (ft_putstr_fd("Error cannot access file\n", 2));
}

void	sig_all(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGSTOP, sig_handler);
	signal(SIGQUIT, sig_handler);
}

void	save_arg(char **cpy, int i, char **env)
{
	static char **arg;
	static int	j = 0;
	int			k;

	if (i > 0)
	{
		if (j != i && i > 1)
			save_hist(env, cpy[i - 2], 1);
		j = i;
		arg = cpy;
	}
	else if (i == 0)
	{
		k = 0;
		while (arg[k + 1])
			ft_putendl(arg[k++]);
	}
}

char	*mini_tild(char *s, int j)
{
	char	*t;
	int		i;
	int		l;

	i = indexinenv("HOME", save_env(0, 0));
	if (!save_env(0, 0)[i])
		return (ft_strdup("./"));
	t = ft_strdup(&save_env(0, 0)[i][5]);
	l = ft_strlen(t);
	i = 1;
	while (s[i] && i <= j)
	{
		ft_realloc(&t);
		t[l++] = s[i++];
	}
	return (t);
}
