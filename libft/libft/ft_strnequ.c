/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:49:34 by jbert             #+#    #+#             */
/*   Updated: 2014/01/18 20:00:17 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	a;

	a = 0;
	if ((!s1 && s2) || (!s2 && s1))
		return (0);
	else if (s1 == s2)
		return (1);
	else
	{
		while (a < n && s1[a] && s2[a] && s1[a] == s2[a])
			a++;
		if (a == n || (s1[a] == s2[a] && s1[a] == '\0'))
			return (1);
		else
			return (0);
	}
}
