/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:48:41 by jbert             #+#    #+#             */
/*   Updated: 2014/06/19 17:24:14 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		i;
	int		j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (ft_strdup("\0"));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	a = (char *)ft_memalloc(sizeof(char) * (i + j + 1));
	i = 0;
	j = 0;
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j])
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}
