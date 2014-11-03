/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:26:46 by jbert             #+#    #+#             */
/*   Updated: 2014/06/19 17:49:52 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**nanana(char **temp, char const *s, int *a)
{
	if (a[2] > 0)
	{
		temp[a[1]][a[2]] = '\0';
		a[1]++;
	}
	if (((char *)s)[a[0]] == '=')
		a[0]++;
	if ((((char *)s)[a[0]] == ';' || ((char *)s)[a[0]] == '|' || \
			((char *)s)[a[0]] == '&') || \
			((char *)s)[a[0]] == '>' || ((char *)s)[a[0]] == '<')
	{
		temp[a[1]] = (char *)ft_memalloc(sizeof(char) * 2);
		temp[a[1]][0] = ((char *)s)[a[0]++];
		temp[a[1]][1] = '\0';
		a[1]++;
	}
	return (temp);
}

char	**cpy_char(char const *s, char c, int *a, char **temp)
{
	while (((char *)s)[a[0]] && ((char *)s)[a[0]] != c && \
			((char *)s)[a[0]] != ';' && ((char *)s)[a[0]] != '&' && \
			((char *)s)[a[0]] != '|' && ((char *)s)[a[0]] != '>' && \
			((char *)s)[a[0]] != '<' && ((char *)s)[a[0]] != '=' && \
			((char *)s)[a[0]] != '\t' && ((char *)s)[a[0]] != '\n')
		temp[a[1]][a[2]++] = ((char *)s)[a[0]++];
	return (temp);
}

int		w_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 2;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '\t'))
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c && s[i] != '\t' && s[i] != '=' && \
				s[i] != '&' && s[i] != ';' && s[i] != '|' && s[i] != '>' \
				&& s[i] != '<')
			i++;
		if (s[i])
			i++;
	}
	return (++count);
}

char	**ft_strsplit(char const *s, char c)
{
	int		a[4];
	char	**temp;

	a[0] = 0;
	a[1] = 0;
	a[3] = ft_strlen(s);
	if (s == NULL || s[a[0]] == '\0')
		return (NULL);
	temp = (char **)ft_memalloc(sizeof(char *) * (w_count((char *)s, c) + 1));
	while ((char)s[a[0]] && (char)s[a[0]] != '\n' && (char)s[a[0] + 1] != '\n')
	{
		a[2] = 0;
		while ((((char *)s)[a[0]] == c || \
					((char *)s)[a[0]] == '\t') && ((char *)s)[a[0]])
			a[0]++;
		if (s[a[0]])
		{
			temp[a[1]] = (char *)ft_memalloc(sizeof(char) * (a[3] + 1 - a[0]));
			ft_bzero(temp[a[1]], (a[3] + 1 - a[0]));
			temp = cpy_char(s, c, a, temp);
			temp = nanana(temp, s, a);
		}
	}
	temp[a[1]] = NULL;
	return (temp);
}
