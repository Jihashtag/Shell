/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 08:31:58 by jbert             #+#    #+#             */
/*   Updated: 2014/05/24 18:26:11 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_count_char(long *n, long tmp, int *counter, int *neg)
{
	if (*n < 0)
	{
		*n = -(*n);
		tmp = tmp * (-1);
		*neg = -1;
		*counter = *counter + 1;
	}
	while (tmp > 0)
	{
		tmp = (tmp / 10);
		*counter = *counter + 1;
	}
}

static char	*ft_fill_string(long n, int neg, int counter, long tmp)
{
	char	*result;

	ft_count_char(&n, tmp, &counter, &neg);
	result = ft_strnew(counter);
	if (result == NULL)
		return (NULL);
	if (neg == -1)
		result[0] = '-';
	counter--;
	while (n > 0)
	{
		result[counter] = n % 10 + '0';
		counter--;
		n = (n / 10);
	}
	return (result);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		counter;
	int		neg;
	long	tmp;

	tmp = (long)n;
	neg = 1;
	counter = 0;
	if (n == 0)
	{
		result = ft_strdup("0\0");
		return (result);
	}
	result = ft_fill_string((long)n, neg, counter, tmp);
	return (result);
}
