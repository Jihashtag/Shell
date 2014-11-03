/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:07:03 by jbert             #+#    #+#             */
/*   Updated: 2014/04/14 13:22:56 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define RESET(a,b) a = 0; b = 0;

int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;
	int	b;

	if (s1 == NULL)
		return (0);
	RESET(a, b);
	while (s1[a] == s2[a] && s1[a] && s2[a])
	{
		a++;
	}
	b = s1[a] - s2[a];
	return (b);
}
