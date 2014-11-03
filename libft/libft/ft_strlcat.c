/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:43:37 by jbert             #+#    #+#             */
/*   Updated: 2014/01/18 19:58:48 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dstbis;
	const char	*srcbis;
	size_t		n;
	size_t		i;

	dstbis = dst;
	srcbis = src;
	n = size;
	while (n-- != 0 && *dstbis != '\0')
		dstbis++;
	i = dstbis - dst;
	n = size - i;
	if (n == 0)
		return (i + ft_strlen(srcbis));
	while (*srcbis != '\0')
	{
		if (n != 1)
		{
			*dstbis++ = *srcbis;
			n--;
		}
		srcbis++;
	}
	*dstbis = '\0';
	return (i + (srcbis - src));
}
