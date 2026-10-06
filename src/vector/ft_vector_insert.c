/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:34:00 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"
#include "ft/ft_mem.h"

static int	grow_if_full(t_vector *vector)
{
	if (vector->len < vector->capacity)
		return (1);
	if (vector->capacity == 0)
		return (ft_vector_reserve(vector, VECTOR_MIN_CAPACITY));
	if (vector->capacity > (size_t)-1 / 2)
		return (0);
	return (ft_vector_reserve(vector, vector->capacity * 2));
}

int	ft_vector_insert(t_vector *vector, const void *elem, size_t index)
{
	unsigned char	*pos;

	if (!vector || !elem || index > vector->len)
		return (0);
	if (!grow_if_full(vector))
		return (0);
	pos = (unsigned char *)vector->data + index * vector->elem_size;
	ft_memmove(pos + vector->elem_size, pos,
		(vector->len - index) * vector->elem_size);
	ft_memcpy(pos, elem, vector->elem_size);
	vector->len++;
	return (1);
}
