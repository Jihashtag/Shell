/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:43:28 by jbert             #+#    #+#             */
/*   Updated: 2013/12/01 00:36:59 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	size_t	verif;

	i = 0;
	verif = 0;
	while (((char *)s2)[verif] && ((char *)s2)[verif] != (unsigned char)c)
		verif++;
	if (verif > n || verif == ft_strlen(s2))
	{
		while (i < n)
		{
			((char *)s1)[i] = ((char *)s2)[i];
			i++;
		}
		return (NULL);
	}
	else
	{
		while (i <= verif)
		{
			((char *)s1)[i] = ((char *)s2)[i];
			i++;
		}
		return (&((char *)s1)[i]);
	}
}
