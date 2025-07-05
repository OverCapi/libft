/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:34:00 by capi              #+#    #+#             */
/*   Updated: 2025/07/05 12:51:00 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vector_insert(t_vector *vector, void *data, size_t index)
{
	void	*ptr;

	index *= vector->data_size;
	if (!vector || !data || index >= vector->len)
		return ;
	ptr = vector->data + index;
	if (vector->max_size < vector->len + vector->data_size)
	{
		ft_vector_reserve(vector, vector->max_size * 2 + vector->data_size);
		if (vector->max_size < vector->len + vector->data_size)
			return ;
	}
	ft_memmove(ptr + vector->data_size, ptr, \
				(vector->data + (vector->len * vector->data_size)) - ptr);
	ft_memcpy(ptr, data, vector->data_size);
}
