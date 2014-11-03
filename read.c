/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:41:42 by jbert             #+#    #+#             */
/*   Updated: 2014/06/25 17:15:22 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_strcar(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	all_five(int l, char *s)
{
	int	i;

	i = ft_strlen(s);
	if (!(l % 5))
		ft_putstr("\n");
	else
	{
		while (i < 15)
		{
			ft_putstr(" ");
			i++;
		}
	}
}

char	*wc_bis(char *arg, int i, char *dir)
{
	char			*s;
	int				l;
	DIR				*d;
	struct dirent	*t;

	if ((d = opendir(dir)) && ft_putstr("\n"))
		s = 0;
	if (((l = 0) || l == 0) && !d)
		return (NULL);
	while ((t = readdir(d)))
	{
		if (!ft_strncmp(t->d_name, arg, i) || i < 0)
		{
			if (ft_putstr(t->d_name) && !s)
				s = ft_strdup(t->d_name);
			else
				l++;
			all_five(l, t->d_name);
		}
	}
	if (ft_putstr("\n") && !closedir(d) && s && !l)
		return (s);
	else if (s)
		ft_free(s);
	return (NULL);
}

char	*sub_to(char *s, int k)
{
	int		i;
	int		j;
	char	*t;

	i = k;
	while (i >= 0 && s[i] != '/')
		i--;
	if (i < 0)
		return (ft_strdup("./"));
	if (s[0] == '~')
		return (mini_tild(s, i));
	t = ft_memalloc(sizeof(char) * (i + 2));
	j = 0;
	while (s[j] && j <= i)
	{
		t[j] = s[j];
		j++;
	}
	return (t);
}

int		wild_card(char **arg, int k, int *j)
{
	int				i;
	unsigned int	l;
	char			*s;
	char			*t;

	i = *j;
	while (arg[k][i - 1] && arg[k][i - 1] != ' ')
		i--;
	t = sub_to(&arg[k][i], *j);
	if (ft_strcmp(t, "./"))
		i = *j;
	while (ft_strcmp(t, "./") && arg[k][i - 1] != '/')
		i--;
	if ((s = wc_bis(&arg[k][i], (*j - i - 1), t)) && s != NULL)
	{
		l = *j - i;
		while (s[l])
			insert(&arg, &k, j, s[l++]);
		insert(&arg, &k, j, ' ');
		ft_free(s);
		ft_free(t);
		return (1);
	}
	ft_free(t);
	return (0);
}
