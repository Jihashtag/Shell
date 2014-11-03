/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:38:24 by jbert             #+#    #+#             */
/*   Updated: 2013/12/01 20:29:28 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	sizeee(int s)
{
	static int size;

	if (s > 0)
		size = s;
	return (size);
}

int	counterr(char *s, char c)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count ++;
		i++;
	}
	sizeee(i + 1);
	return (count + 1);
}

char	**ft_strsplit2(char const *s, char c)
{
	int		a;
	int		b;
	int		d;
	char	**temp;

	a = 0;
	b = 0;
	if (s == NULL || s[a] == '\0')
		return (NULL);
	temp = (char **) ft_memalloc(sizeof(char *) * (counterr((char *)s, c)));
	while (((char *)s)[a])
	{
		while (((char *)s)[a] == c && ((char *)s)[a])
			a++;
		temp[b] = (char *) ft_memalloc(sizeof(char) * (sizeee(0) + 1 - a));
		d = 0;
		while (((char *)s)[a] != c && ((char *)s)[a])
			temp[b][d++] = ((char *)s)[a++];
		temp[b][d] = '\0';
		b++;
	}
	temp[b] = NULL;
	return (temp);
}
