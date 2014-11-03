/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:51:20 by jbert             #+#    #+#             */
/*   Updated: 2014/06/09 17:36:42 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define RESET(a, b) a = 0; b = 0;

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;
	int				b;

	if (s1 == NULL || s2 == NULL)
		return (0);
	RESET(a, b);
	if (s1 == s2)
		return (0);
	while (s1[a] == s2[a] && s1[a] && s2[a] && a < n)
		a++;
	b = s1[a] - s2[a];
	return (b);
}

int	ft_strncmp2(const char *s1, const char *s2, int n)
{
	int	a;
	int	b;

	if (s1 == NULL || s2 == NULL)
		return (0);
	RESET(a, b);
	if (s1 == s2 || n < 0)
		return (0);
	while (s1[a] == s2[a] && s1[a] && s2[a] && a < n)
		a++;
	b = s1[a] - s2[a];
	return (b);
}
