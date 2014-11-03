/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 18:55:43 by jbert             #+#    #+#             */
/*   Updated: 2014/06/21 05:08:55 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_tild(char **argv, char **env)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '~')
			tild(env, argv, i);
		i++;
	}
}

char	**save_env(char **env, int n)
{
	static char	**tmp = NULL;

	if (n)
		tmp = env;
	return (tmp);
}

void	ft_init_term(struct termios *term)
{
	char	buffer[2048];

	tgetent(buffer, getenv("TERM"));
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

void	ft_restore_term(struct termios *term)
{
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
	term->c_lflag |= ICANON;
	tcsetattr(0, 0, term);
}

void	ft_free(void *t)
{
	if (t && ((char *)t)[0])
		free(t);
	t = NULL;
}
