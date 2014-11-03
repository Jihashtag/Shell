/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 00:07:54 by jbert             #+#    #+#             */
/*   Updated: 2014/05/12 07:30:09 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		write_char(va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	ft_putstr(s);
	return ((int)ft_strlen(s));
}

int		write_int(va_list ap)
{
	return (ft_putnbr(va_arg(ap, int)));
}

int		write_c(va_list ap)
{
	ft_putchar(va_arg(ap, int));
	return (1);
}

int		ft_treatment(char *s, int j, va_list ap)
{
	if (s[j] == 's')
		return (write_char(ap));
	else if (s[j] == 'd')
		return (write_int(ap));
	else if (s[j] == 'c')
		return (write_c(ap));
	else if (ft_isprint(s[j]))
		return (0);
	else
		return (0);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		j;
	int		count;

	va_start(ap, format);
	count = 0;
	j = 0;
	while (format[j])
	{
		if (format[j] == '%' && (count -= 1))
		{
			j++;
			while (format[j] == 32 && format[j] && --count)
				j++;
			if (format[j] != '%' && format[j] != '\t')
				count += ft_treatment(format, j++, ap) - 1;
		}
		write(1, &format[j], 1);
		j++;
	}
	va_end(ap);
	return (count + j);
}
