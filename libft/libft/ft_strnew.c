/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:29:56 by jbert             #+#    #+#             */
/*   Updated: 2014/04/14 13:25:51 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size)
		{
			new[i] = '\0';
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
