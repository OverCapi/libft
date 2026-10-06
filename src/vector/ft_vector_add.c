/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:08:38 by capi              #+#    #+#             */
/*   Updated: 2025/07/05 12:30:55 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_add(t_vector *vector, void *data)
{
	void	*index;

	if (!vector || !data)
		return ;
	if (vector->max_size < vector->len + vector->data_size)
	{
		ft_vector_reserve(vector, vector->max_size * 2 + vector->data_size);
		if (vector->max_size < vector->len + vector->data_size)
			return ;
	}
	index = vector->data + vector->len;
	ft_memcpy(index, data, vector->data_size);
	vector->len += vector->data_size;
}
