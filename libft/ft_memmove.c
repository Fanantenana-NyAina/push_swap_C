/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 01:48:02 by tsirakot          #+#    #+#             */
/*   Updated: 2026/02/12 03:08:01 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	if (!dest && !src)
		return (NULL);
	b = src;
	a = dest;
	if (a < b)
	{
		while (n--)
			*a++ = *b++;
	}
	else
	{
		while (n--)
			a[n] = b[n];
	}
	return (dest);
}
