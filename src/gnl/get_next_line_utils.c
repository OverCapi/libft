/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:57:06 by llemmel           #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_internal.h"

size_t	ft_strlen_gnl(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	if (str[len] == c && c != '\0')
		return (len + 1);
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	size_t	total_len;

	if (!s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	total_len = ft_strlen(s1) + ft_strlen_gnl(s2, '\n') + 1;
	dest = malloc(total_len);
	if (!dest)
		return (free(s1), NULL);
	ft_strlcpy(dest, s1, total_len);
	ft_strlcat(dest, s2, total_len);
	free(s1);
	return (dest);
}
