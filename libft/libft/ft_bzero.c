/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:11:10 by jbert             #+#    #+#             */
/*   Updated: 2014/06/19 17:52:48 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	a;

	a = 0;
	if (s != NULL)
	{
		while (a < n)
		{
			((char *)s)[a] = 0;
			a++;
		}
	}
}
