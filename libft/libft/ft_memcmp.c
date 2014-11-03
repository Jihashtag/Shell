/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 22:52:23 by jbert             #+#    #+#             */
/*   Updated: 2014/01/18 19:53:11 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	int				a;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1 == s2)
		return (0);
	else
	{
		i = 0;
		while (i < n && ((char *)s1)[i] == ((char *)s2)[i])
			i++;
		if (i < n)
			a = ((char *)s1)[i] - ((char *)s2)[i];
		else
			a = 0;
		return (a);
	}
}
