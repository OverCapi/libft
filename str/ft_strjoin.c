/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:20:23 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/30 14:04:55 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	total_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *)malloc(total_len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, total_len);
	ft_strlcat(dest, s2, total_len);
	return (dest);
}
