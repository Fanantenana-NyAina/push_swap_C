/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 02:54:45 by tsirakot          #+#    #+#             */
/*   Updated: 2026/02/12 03:05:36 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	unsigned int	src_len;

	len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= len)
		return (size + src_len);
	i = 0;
	j = len;
	while (src[i] != '\0' && i < size - len - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (len + src_len);
}
