/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:54:57 by jbert             #+#    #+#             */
/*   Updated: 2014/04/14 13:33:41 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*a;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((a = (char *)malloc(sizeof(char) * ft_strlen(s))))
	{
		WHILE(i)
		while (s[i])
		{
			if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			{
				k = i;
				WHILE(k)
				if (s[k] == '\0')
					i = k;
			}
			a[j++] = s[i++];
		}
		return (a);
	}
	else
		return (NULL);
}
