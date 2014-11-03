/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 17:42:07 by jbert             #+#    #+#             */
/*   Updated: 2014/06/25 17:42:11 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	sig_handler(int signum)
{
	char	c;

	signal(signum, SIG_IGN);
	if (signum == SIGSTOP)
		ft_putstr("\nPas de ctrl+z\n$>");
	if (signum == SIGTSTP)
		ft_putstr("\nPas de ctrl+z\n$>");
	if (signum == SIGINT || signum == SIGQUIT)
	{
		c = 8;
		write(1, &c, 1);
		write(1, &c, 1);
		c = 32;
		write(1, &c, 1);
		write(1, &c, 1);
		c = 8;
		write(1, &c, 1);
		write(1, &c, 1);
		if (prog(0))
			ft_putstr("\nProgram stopped\n\n");
	}
	signal(signum, sig_handler);
}

void	norme_one(char ***argv, int *ac, char ***av, char *flag)
{
	dup_tb(argv, av, 0, ac);
	if ((*argv)[(*ac)])
		flag[0] = (*argv)[(*ac)][0];
	if (flag[0] == '>' && (*argv)[(*ac) + 1] && (*argv)[(*ac) + 1][0] != '>')
		trash_bin(*argv, ac, NULL, NULL);
}

int		norme_two(char ***argv, int *ac, char *flag)
{
	if ((*argv)[(*ac) + 1] && (*argv)[(*ac) + 1][0] != ';' && \
			(*argv)[(*ac) + 1][0] != '|' && (*argv)[(*ac) + 1][0] != '>' && \
			(*argv)[(*ac) + 1][0] != '<' && (*argv)[(*ac) + 1][0] != '&')
		return (1);
	else
		return (0);
	(void)flag;
}

void	norme_last(char *flag, int *ac, char **argv)
{
	int		fd;
	char	buf[1025];

	if (flag[0] == '<')
	{
		if (argv[(*ac) + 1])
			fd = open(argv[++(*ac)], O_RDONLY);
		(*ac) = argv[(*ac) + 1] ? (*ac) : (*ac) + 1;
		if (fd > 0)
			dup2(fd, 0);
		close(fd);
	}
	if (flag[0] == '>' && argv[(*ac) + 1] && argv[(*ac) + 1][0] == '>')
	{
		(*ac)++;
		if (argv[(*ac) + 1])
			fd = open(argv[++(*ac)], O_RDWR | O_CREAT, S_IRWXU);
		if (!argv[(*ac) + 1])
			(*ac)++;
		while (read(fd, buf, 1024))
			;
		if (fd > 0)
			dup2(fd, 1);
		close(fd);
	}
}

void	free_tb(char **tb, char **tb2, char **tb3, int nb)
{
	int	i;

	i = 0;
	while (tb[i])
		i++;
	while (--i >= 0)
		ft_free(tb[i]);
	if (tb)
		ft_free(tb);
	if (nb >= 2 && tb2 && (i == 0 || (i = 0)))
	{
		while (tb2[i])
			i++;
		while (--i >= 0)
			ft_free(tb2[i]);
		ft_free(tb2);
	}
	if (nb >= 3 && tb3 && (i == 0 || (i = 0)))
	{
		while (tb3[i])
			i++;
		while (--i >= 0)
			ft_free(tb3[i]);
		ft_free(tb3);
	}
}
