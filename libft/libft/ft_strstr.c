/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:42:59 by jbert             #+#    #+#             */
/*   Updated: 2014/04/14 13:28:26 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	char		*dst;
	char		*s1_tmp;
	char		*s2_tmp;

	i = 0;
	j = 0;
	s1_tmp = (char *)s1;
	s2_tmp = (char *)s2;
	if (s2_tmp[j] == '\0')
		return (s1_tmp);
	while (s1_tmp[i] && s2_tmp[j])
	{
		if (s1_tmp[i] == s2_tmp[j] && j == 0)
			dst = &s1_tmp[i];
		if (s1_tmp[i] == s2_tmp[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (s2_tmp[j] == '\0')
		return (dst);
	return (NULL);
}
