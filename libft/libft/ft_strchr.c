/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:34:59 by jbert             #+#    #+#             */
/*   Updated: 2014/01/26 16:09:30 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	a;

	if ((s == NULL || !s || s[0] == '\0') && (unsigned char)c != '\0')
		return (NULL);
	a = 0;
	while (s[a] != c && s[a] != '\0')
		a++;
	if (s[a] == c)
		return (&((char *)s)[a]);
	else
		return (NULL);
}
