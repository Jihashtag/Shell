# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbert <jbert@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 23:05:58 by jbert             #+#    #+#              #
#    Updated: 2014/06/24 18:15:25 by jbert            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	42sh

SRC		=	fichier1.c	fichier2.c	ft_sh1.c	last.c	ft_sh2.c	new.c	read.c	term.c\
			norme.c	nana.c	norme2.c	norme3.c	norme4.c	ft_strsplit.c

OBJ		=	$(SRC:.c=.o)

FLAG	=	-Wall -Wextra -Werror -g3

$(NAME):
			make all -C libft/
			@echo ".c to .o"
			@gcc $(FLAG) -c $(SRC)
			@echo "Executable"
			@echo ""
			@gcc $(FLAG) -o $(NAME) $(OBJ) libft/libftprintf.a -ltermcap

all: $(NAME)

clean:
		@echo "clean"
		@echo ""
		make clean -C libft/
		@rm -f $(OBJ)

fclean:
		@echo "fclean"
		@echo ""
		make fclean -C libft/
		@rm -f $(OBJ) $(NAME)

re:	fclean all

.PHONY: all NAME clean fclean re
