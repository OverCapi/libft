/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:09:38 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/27 23:52:05 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*dest;

	len_s = ft_strlen(s);
	dest = (char *)malloc((len_s + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, len_s + 1);
	return (dest);
}
