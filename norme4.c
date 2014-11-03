/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 04:30:06 by jbert             #+#    #+#             */
/*   Updated: 2014/06/21 04:32:53 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		excla_dot(char **arg, int k, int l, int i)
{
	int	m;

	m = 0;
	while (arg[l][m])
	{
		if (ft_strcar(&arg[k][i], ' ') > 0)
			arg[k][i++] = arg[l][m++];
		else
			insert(&arg, &k, &i, arg[l][m++]);
	}
	insert(&arg, &k, &i, ' ');
	return (i);
}

int		can_go_wild(int	i)
{
	static int	save = 0;
	int			t;

	if (i != 0)
	{
		t = save;
		save = i;
		return (t);
	}
	return (save);
}

int		srchsmtg(char **arg, int k, int *j)
{
	int	i;
	int	l;

	i = 0;
	while (arg[k][i] && arg[k][i] != '!')
		i++;
	if (arg[k][i] == '!' && arg[k][i + 1] != '!')
	{
		l = k - 1;
		while (l >= 0 && ft_strncmp2(arg[l], &arg[k][i + 1], \
					ft_strcar(&arg[k][i + 1], ' ') - 1))
			l--;
		if (l >= 0)
			*j = excla_dot(arg, k, l, i);
		else
			return (-1);
		return (1);
	}
	else if (can_go_wild(0) > 0 && wild_card(arg, k, j))
		return (1);
	return (-1);
}

int		analyse_rd(int *i, t_env *env, char **arg, int *k)
{
	int		j;

	j = ((char)*(unsigned int *)(env->rd) == '\t') ? srchsmtg(arg, *k, i) : 0;
	if (*(unsigned int *)(env->rd) == 127 && (j = 1) && (*i) > 0)
		delete(&arg, k, i);
	else if ((char)*(unsigned int *)(env->rd) == '\n' && \
			(arg[*k][ft_strlen(arg[*k])] = *(unsigned int *)(env->rd)))
		return (0);
	else if (*(unsigned int *)(env->rd) == 4479771 && (j = 1))
		left(arg, i, k);
	else if (*(unsigned int *)(env->rd) == 4414235)
		j = right(j, arg, i, k) > 0 ? 1 : 2;
	else if (*(unsigned int *)(env->rd) == 4348699)
		j = down(arg, k, j, i) > 0 ? 1 : 2;
	else if (*(unsigned int *)(env->rd) == 4283163)
		j = up(arg, k, j, i) > 0 ? 1 : 2;
	else if (j != 0)
		erase_c(4, &(env->term));
	else
		j = ft_isprint((char)*(unsigned int *)env->rd) - 1;
	move_curs(arg, k, i, &(env->term));
	if (j != 0)
		return (0);
	return (1);
}

int		down(char **arg, int *k, int j, int *i)
{
	if ((*k) < 99 && arg[(*k) + 1])
		(*k)++;
	else
		(*k) = 0;
	while (arg[*k][j] != '\n' && arg[*k][j] != '\0')
		j++;
	if (arg[*k][j] == '\n')
		arg[*k][j] = '\0';
	(*i) = j;
	return (j);
}
