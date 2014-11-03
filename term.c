/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:43:02 by jbert             #+#    #+#             */
/*   Updated: 2014/06/25 16:45:09 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_realloc(char **a)
{
	char	*tmp;
	int		j;

	tmp = ft_memalloc(sizeof(char) * ft_strlen(*a) + 1);
	j = 0;
	while ((*a)[j])
	{
		tmp[j] = (*a)[j];
		j++;
	}
	tmp[j] = '\0';
	if (*a)
		ft_free(*a);
	*a = (char *)ft_memalloc(sizeof(char) * j + 2);
	j = 0;
	while (tmp[j])
	{
		(*a)[j] = tmp[j];
		j++;
	}
	(*a)[j] = '\0';
	ft_free(tmp);
}

void	insert(char ***arg, int *k, int *i, char rd)
{
	int		j;

	j = ft_strlen((*arg)[*k]) + 1;
	ft_realloc(&((*arg)[*k]));
	while (j > (*i))
	{
		((*arg)[*k])[j] = ((*arg)[*k])[j - 1];
		j--;
	}
	((*arg)[*k])[(*i)++] = rd;
}

int		no_nme(t_env *env, int *i, int *k, char ***arg)
{
	int		j;

	if (*(unsigned int *)(env->rd) == 4)
	{
		erase_c(2, &(env->term));
		return (0);
	}
	if ((char)*(unsigned int *)(env->rd) == '\n')
	{
		j = ft_strlen((*arg)[*k]);
		if (j == 0)
		{
			(*arg)[*k][j] = ' ';
			(*arg)[*k][j + 1] = '\0';
		}
		return (1);
	}
	if (analyse_rd(i, env, *arg, k))
	{
		insert(arg, k, i, (char)*(unsigned int *)(env->rd));
		move_curs(*arg, k, i, &(env->term));
	}
	return (1);
}

void	clear_cp(void)
{
	pid_t		fk;
	static int	t = 0;
	char		*clear[4];

	if (t == 0)
		fk = fork();
	else
		fk = -1;
	if (fk == -1)
		return ;
	if (fk > 0)
	{
		waitpid(fk, &t, WUNTRACED);
		kill(fk, 6);
		return ;
	}
	else
	{
		clear[0] = "/usr/bin/osascript";
		clear[1] = "-e";
		clear[2] = "set the clipboard to {}";
		clear[3] = NULL;
		execve(clear[0], clear, NULL);
		exit(-1);
	}
}

int		ft_read(char ***arg, int *k)
{
	t_env	env;
	int		i;

	ft_init_term(&(env.term));
	have_to_go(save_env(0, 0));
	i = 0;
	move_curs(*arg, k, &i, &(env.term));
	can_go_wild(1);
	ft_bzero((env.rd), sizeof(char) * 5);
	while ((char)*(unsigned int *)(env.rd) != '\n')
	{
		/*clear_cp();*/
		ft_bzero((env.rd), sizeof(char) * 5);
		read(0, (env.rd), 4);
		if (!no_nme(&env, &i, k, arg))
			return (0);
	}
	can_go_wild(-1);
	while (srchsmtg(*arg, *k, &i) > 0)
		;
	ft_restore_term(&(env.term));
	return (ft_strlen((*arg)[*k]));
}
