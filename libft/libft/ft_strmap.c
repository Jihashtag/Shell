/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:34:52 by jbert             #+#    #+#             */
/*   Updated: 2014/04/14 13:23:53 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	int		a;

	a = 0;
	if (s)
	{
		while (s[a])
			a++;
		temp = (char *)malloc(sizeof(char) * (a + 1));
		a = 0;
		while (s[a])
		{
			temp[a] = f(s[a]);
			a++;
		}
	}
	else
		temp = NULL;
	return (temp);
}
