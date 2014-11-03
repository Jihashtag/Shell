/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:11:16 by jbert             #+#    #+#             */
/*   Updated: 2014/06/24 18:42:57 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_envsearch(char *wut, char ***env)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	while (wut[j] && wut[j] != '=')
		j++;
	while ((*env)[i] && ft_strncmp((*env)[i], wut, j - 1))
		i++;
	if (!(*env)[i])
	{
		tb_realloc(env, 0);
		buf = (char *)ft_memalloc(sizeof(char) * 2049);
		ft_bzero(buf, sizeof(char) * 2048);
		buf = getcwd(buf, 2048);
		(*env)[i] = ft_strjoin(wut, buf);
		if (buf)
			ft_free(buf);
		(*env)[i + 1] = NULL;
	}
	return (&((*env)[i][j + 1]));
}

int		main(int ac, char **av, char **env)
{
	static char		**arg = 0;
	char			**argv;
	static int		i = 0;

	dup2(1, 0);
	ft_putstr_fd("Bienvenu sur le 42sh, entrez votre commande\n", 2);
	while (1)
	{
		sig_all();
		env = save_env(env, 0) ? save_env(env, 0) : save_env(env, 1);
		if (((!arg && (i == 0 || (i = 0))) || \
			(arg && !arg[i])) && tb_realloc(&arg, 1))
			arg[i] = ft_strdup("\0");
		ac = ft_read(&arg, &i);
		if (ac <= 0 && ft_putstr("\nExit\n"))
			exit(0);
		argv = ft_strsplit(arg[i], ' ');
		while (arg[i] && (ft_strlen(arg[i]) > 2 || arg[i][0] != ' '))
			i++;
		save_arg(arg, i + 1, env);
		if (argv[0] != NULL && argv[0][0])
			pre_treat(argv, env, ac, av);
		free_tb(argv, 0, 0, 1);
	}
	return (0);
}

void	ft_echo(char **av, char **env)
{
	int	i;
	int	f;

	i = 1;
	if (av[i] && !ft_strcmp(av[i], "-n"))
		i++;
	f = i;
	while (av[i])
	{
		if (av[i][0] == '$' && env[indexinenv(&av[i][1], env)])
			ft_putstr(&env[indexinenv(&av[i][1], env)]\
					[ft_strlen(av[i])]);
		else
			ft_putstr(av[i]);
		i++;
		if (av[i])
			ft_putchar(' ');
	}
	if (f == 1)
		ft_putchar('\n');
}

void	without_env(char **argv, char **env)
{
	char	**tmp;

	if (!argv[1])
		return ((void)ft_env(env));
	if (argv[1] && ft_strcmp(argv[1], "-i") && \
			ft_strcmp(argv[1], "-I"))
		return ((void)ft_putendl_fd("env : env [-i cmd]", 2));
	tmp = NULL;
	tmp = get_path(tmp);
	treat_prog(&argv[2], tmp);
	if (tmp[0])
		ft_free(tmp[0]);
	if (tmp)
		ft_free(tmp);
}

int		treat_prog(char **argv, char **env)
{
	ft_tild(argv, env);
	if (argv[0] == NULL)
		return (0);
	if (argv[0][0] == '\0')
		return (0);
	if (CMP("exit", "quit"))
		exit(ft_atoi(argv[1]));
	else if (!(ft_strcmp(argv[0], "echo")))
		ft_echo(argv, env);
	else if (!(ft_strcmp(argv[0], "history")))
		save_arg(0, 0, 0);
	else if (!(ft_strcmp(argv[0], "cd")))
		return (ft_cd(argv, env));
	else if (CMP("env", "env -i"))
		without_env(argv, env);
	else if (CMP("i", "je"))
		return (love(argv));
	else if (CMP("editeur", "write"))
		writor(argv);
	else if (CMP("setenv", "unsetenv"))
		env = envnmt(argv, &env);
	else if (other(argv, env) < 0)
		return (ft_printf("%s: isn't a cmd or an error occured\n", argv[0]));
	save_env(env, 1);
	return (0);
}
