/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:41:00 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/30 14:04:55 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static inline int	is_in_set(char c, char const *set)
{
	return (ft_strchr(set, c) != NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set) == 1)
		start++;
	while (end > start && is_in_set(s1[end], set) == 1)
		end--;
	if (is_in_set(s1[end], set) == 1)
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
