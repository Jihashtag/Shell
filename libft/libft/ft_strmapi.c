/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:39:06 by jbert             #+#    #+#             */
/*   Updated: 2014/04/14 13:24:11 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	unsigned int	a;

	a = 0;
	if (s)
	{
		while (s[a])
			a++;
		temp = (char *)malloc(sizeof(char) * (a + 1));
		a = 0;
		while (s[a])
		{
			temp[a] = f(a, s[a]);
			a++;
		}
	}
	else
		temp = NULL;
	return (temp);
}
