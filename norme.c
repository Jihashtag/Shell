/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:44:43 by jbert             #+#    #+#             */
/*   Updated: 2014/06/25 17:11:13 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	erase_c(int n, struct termios *term)
{
	int		j;

	j = 0;
	while (j < n)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tputs(tgetstr("dc", NULL), 1, tputs_putchar);
		tcsetattr(0, 0, term);
		j++;
	}
}

void	delete(char ***arg, int *k, int *i)
{
	int		j;

	j = (*i);
	while (j <= (int)ft_strlen((*arg)[*k]))
	{
		((*arg)[*k])[j - 1] = ((*arg)[*k])[j];
		j++;
	}
	(*i)--;
}

void	move_curs(char **arg, int *k, int *i, struct termios *term)
{
	int		j;
	char	prpt[2049];
	char	*prompt;

	ft_bzero(prpt, sizeof(char) * 2049);
	getcwd(prpt, 2048);
	prompt = ft_strjoin(ft_strrchr(prpt, '/'), " > ");
	j = ft_strlen(arg[*k]);
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, tputs_putchar);
	erase_c(j + ft_strlen(prompt), term);
	tputs(tgetstr("dl", NULL), 1, tputs_putchar);
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, tputs_putchar);
	tputs(tgetstr("dl", NULL), 1, tputs_putchar);
	ft_putstr(prompt);
	ft_free(prompt);
	ft_putstr(arg[*k]);
	while (j > (*i))
	{
		j--;
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
	}
}

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		prog(int j)
{
	static int	i = 0;
	int			tmp;

	tmp = i;
	i = j;
	return (tmp);
}
