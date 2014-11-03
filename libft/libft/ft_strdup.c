/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:59:58 by jbert             #+#    #+#             */
/*   Updated: 2014/06/19 16:59:20 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	a;
	size_t	i;

	i = 0;
	while (s1 && s1[i])
		i++;
	s2 = (char *)ft_memalloc(sizeof(char) * (i + 1));
	a = 0;
	while (s1 && s1[a])
	{
		s2[a] = s1[a];
		a++;
	}
	s2[a] = '\0';
	return (s2);
}
