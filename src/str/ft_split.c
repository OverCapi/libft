/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:21:18 by llemmel           #+#    #+#             */
/*   Updated: 2026/10/06 22:39:35 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_str.h"

static size_t	count_words(char const *s, char c)
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

static char	**fill_words(char **strs, char const *s, char c)
{
	size_t	word;
	size_t	start;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i == start)
			break ;
		strs[word] = ft_substr(s, start, i - start);
		if (!strs[word++])
			return (ft_free_split(strs), NULL);
	}
	strs[word] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	return (fill_words(strs, s, c));
}
