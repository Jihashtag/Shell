/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 22:45:53 by jbert             #+#    #+#             */
/*   Updated: 2013/11/29 19:21:36 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cbis;
	unsigned int	i;

	i = 0;
	cbis = c;
	while (i < n)
	{
		if (((char *)s)[i] == cbis)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
