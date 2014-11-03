/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:53:27 by jbert             #+#    #+#             */
/*   Updated: 2014/05/23 18:11:27 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	k;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == 32 || (str[i] <= 14 && str[i] >= 8))
		i++;
	if (!(k = 0) && str[i] == '-')
	{
		k = i;
		i++;
	}
	if (!(res = 0) && str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[k] == '-')
		return (-res);
	else
		return (res);
}
