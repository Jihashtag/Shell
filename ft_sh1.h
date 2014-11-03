/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:11:16 by jbert             #+#    #+#             */
/*   Updated: 2014/06/24 18:15:58 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_SH1_H
# define _FT_SH1_H

# include <unistd.h>
# include <stdlib.h>
#include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <curses.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
#include <sys/types.h>
# include <signal.h>
# include "./libft/printf.h"

# define DBG(x) ft_putendl_fd(x, 2);
# define CMP(x,y) !(ft_strcmp(argv[0], x)) || !(ft_strcmp(argv[0], y))
# define ARG 100
# define EDITOR 10000
# define ISENV(x,y) env[i][0] != x || env[i][1] != y
# define POO (ft_strlen(env[index]) - 3 + ft_strlen(temp))

typedef struct		s_env
{
	char			rd[5];
	struct termios	term;
}					t_env;
char				**ft_strsplit2(char const *s, char c);
void				sig_handler(int signum);
int					treat_prog(char **argv, char **ev);
int					ft_cd(char **argv, char **env);
void				writor(char **argv);
char				**old_path(char *wut, char **env);
int					love(char **argv);
void				ft_env(char **env);
void				tild(char **env, char **argv, int j);
int					other(char **argv, char **env);
int					execute(char **argv, char *temp, char **env);
char				**envnmt(char **argv, char ***env);
char				*ft_envsearch(char *wut, char ***env);
int					indexinenv(char *wut, char **env);
int					pre_treat(char **argv, char **env, int ac, char **av);
int					trash_bin(char **av, int *ac, char **env, char **els);
void				dup_tb(char ***argv, char ***av, int i, int *ac);
void				norme_one(char ***argv, int *ac, char ***av, char *flag);
int					norme_two(char ***argv, int *ac, char *flag);
void				norme_last(char *flag, int *ac, char **argv);
void				free_tb(char **tb, char **tb2, char **tb3, int nb);
char				**save_env(char **env, int n);
int					tb_realloc(char ***tb, int i);
void				ft_tild(char **argv, char **env);
int					tb_cpy(char ***tb, char **tmp, int j, int k);
void				retab(int *save, int *p, int i);
void				ft_start(char *flag, int *save, int *p);
int					prog(int j);
void				save_arg(char **cpy, int i, char **env);
char				**have_to_go(char **env);
char				**get_path(char **env);
void				sig_all(void);
void				save_hist(char **env, char *l, int i);

char				*mini_tild(char *s, int j);
int					wild_card(char **arg, int k, int *j);
int					ft_strcar(char *s, char c);
int					srchsmtg(char **arg, int k, int *j);
int					excla_dot(char **arg, int k, int l, int i);
void				ft_init_term(struct termios *term);
int					can_go_wild(int	i);
void				ft_restore_term(struct termios *term);
int					analyse_rd(int *i, t_env *env, char **arg, int *k);
int					ft_read(char ***arg, int *k);
void				erase_c(int n, struct termios *term);
int					tputs_putchar(int c);
void				move_curs(char **arg, int *k, int *i, struct termios *term);
void				delete(char ***arg, int *k, int *i);
void				ft_realloc(char **a);
int					up(char **arg, int *k, int j, int *i);
int					down(char **arg, int *k, int j, int *i);
int					left(char **arg, int *i, int *k);
int					right(int j, char **arg, int *i, int *k);
void				insert(char ***arg, int *k, int *i, char rd);
int					srchsmtg(char **arg, int k, int *j);
void				ft_free(void *t);

#endif
