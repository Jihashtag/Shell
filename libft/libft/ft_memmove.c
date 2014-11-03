/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:13:16 by jbert             #+#    #+#             */
/*   Updated: 2014/04/14 13:20:34 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	int	a;

	if (s1 == NULL)
		return (0);
	if (ft_strlen((char *)s1) < ft_strlen((char *)s2))
		return (ft_memcpy(s1, s2, n));
	else
	{
		if (n >= ft_strlen((char *)s1))
		{
			a = ft_strlen((char *)s1);
			return (ft_memcpy(s1, s2, a));
		}
		else
			return (ft_memcpy(s1, s2, n));
	}
}
