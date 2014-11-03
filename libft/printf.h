/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 04:04:19 by jbert             #+#    #+#             */
/*   Updated: 2014/05/12 07:29:12 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

int		write_c(va_list ap);
int		write_int(va_list ap);
int		write_char(va_list ap);
int		ft_treatment(char *s, int j, va_list ap);
int		ft_printf(char *s, ...);

#endif
