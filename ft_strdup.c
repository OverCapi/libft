/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:09:38 by llemmel           #+#    #+#             */
/*   Updated: 2024/10/16 08:55:38 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	size_t	i;
	char	*dest;

	i = 0;
	len_s = ft_strlen(s);
	dest = (char *)malloc((len_s + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < len_s)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
