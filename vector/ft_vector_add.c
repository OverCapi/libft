/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:08:38 by capi              #+#    #+#             */
/*   Updated: 2025/06/30 14:33:02 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vector_add(t_vector *vector, void *data, size_t data_size)
{
	void	*index;

	if (!vector || !data)
		return ;
	if (vector->max_size < vector->len + data_size)
	{
		ft_vector_reserve(vector, vector->max_size * 2 + data_size);
		printf("Alloc, new size: %zu\n", vector->max_size);
		if (vector->max_size < vector->len + data_size)
			return ;
	}
	index = vector->data + vector->len;
	ft_memcpy(index, data, data_size);
	vector->len += data_size;
}
