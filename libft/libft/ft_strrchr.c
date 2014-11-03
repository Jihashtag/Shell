/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:54:14 by jbert             #+#    #+#             */
/*   Updated: 2014/01/18 19:53:59 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	a;

	a = 0;
	if (s == NULL || !s || s[a] == '\0')
		return (NULL);
	while (s[a])
		a++;
	while (s[a] != (unsigned char)c && a > 0)
		a--;
	if (s[a] == (unsigned char)c)
		return ((char *)&s[a]);
	else
		return (NULL);
}
