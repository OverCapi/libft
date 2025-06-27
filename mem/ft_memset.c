/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:15:42 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/28 00:27:26 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static inline size_t	get_size_t_value(unsigned char byte_val)
{
	size_t	val;
	size_t	i;

	val = 0;
	i = 0;
	while (i++ < sizeof(size_t))
		val = (val << 8) | byte_val;
	return (val);
}

void	*ft_memset(void	*s, int c, size_t n)
{
	size_t			*s2;
	size_t			i;
	size_t			val;
	size_t			n_bytes;
	unsigned char	byte_val;

	byte_val = (unsigned char)c;
	val = get_size_t_value(byte_val);
	i = 0;
	s2 = (size_t *)s;
	n_bytes = n / sizeof(size_t);
	while (i != n_bytes)
		s2[i++] = val;
	if (n % sizeof(size_t) != 0)
	{
		i = n_bytes * sizeof(size_t);
		while (i < n)
			((unsigned char *)s)[i++] = byte_val;
	}
	return (s);
}
