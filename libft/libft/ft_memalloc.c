/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:01:04 by jbert             #+#    #+#             */
/*   Updated: 2014/06/19 17:20:30 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*m;

	m = malloc(size);
	if (!m || m == NULL)
	{
		ft_putendl_fd("\nCould not malloc\n", 2);
		exit(-1);
	}
	ft_bzero(m, size);
	return (m);
}
