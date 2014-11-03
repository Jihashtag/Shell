/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:45:45 by jbert             #+#    #+#             */
/*   Updated: 2013/11/29 19:27:28 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if ((!s1 && s2) || (!s2 && s1))
		return (0);
	if (ft_strlen(s1) < ft_strlen(s2) || ft_strlen(s2) < ft_strlen(s1))
		return (0);
	else if (s1 == s2)
		return (1);
	else
		return (0);
}
