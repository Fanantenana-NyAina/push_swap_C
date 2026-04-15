/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:15:11 by tsirakot          #+#    #+#             */
/*   Updated: 2026/02/12 03:05:45 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	real_len;
	size_t	i;
	char	*substring;
	char	*dup;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		dup = ft_strdup("");
		return (dup);
	}
	real_len = s_len - start;
	if (real_len > len)
		real_len = len;
	substring = malloc(real_len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (i < real_len)
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}
