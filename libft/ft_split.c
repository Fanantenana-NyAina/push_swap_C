/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirakot <tsirakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:40:01 by tsirakot          #+#    #+#             */
/*   Updated: 2026/02/12 03:05:32 by tsirakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(char **all, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(all[i]);
		i++;
	}
	free(all);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_word_length(char const *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (len);
}

static char	**ft_create_word(char const *s, char c, size_t word_count)
{
	char	**word;
	size_t	i;
	size_t	j;
	size_t	word_len;

	word = malloc(sizeof(char *) * (word_count + 1));
	if (!word)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		word_len = ft_word_length(s, c, i);
		word[j] = ft_substr(s, i, word_len);
		if (!word[j])
			return (ft_free_all(word, j), NULL);
		i += word_len;
		j++;
	}
	word[j] = NULL;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	return (ft_create_word(s, c, word_count));
}
