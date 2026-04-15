/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:23:27 by tsirakot          #+#    #+#             */
/*   Updated: 2026/02/12 03:05:33 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*x;

	i = 0;
	x = (char *)s;
	while (x[i] && (x[i] != (unsigned char)c))
	{
		i++;
	}
	if (x[i] == (unsigned char)c)
	{
		return (&x[i]);
	}
	return (0);
}
