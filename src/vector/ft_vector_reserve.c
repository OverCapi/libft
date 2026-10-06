/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:39:23 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"
#include "ft/ft_mem.h"

int	ft_vector_reserve(t_vector *vector, size_t new_capacity)
{
	void	*new_data;

	if (!vector)
		return (0);
	if (new_capacity <= vector->capacity)
		return (1);
	if (new_capacity > (size_t)-1 / vector->elem_size)
		return (0);
	new_data = malloc(new_capacity * vector->elem_size);
	if (!new_data)
		return (0);
	ft_memcpy(new_data, vector->data, vector->len * vector->elem_size);
	free(vector->data);
	vector->data = new_data;
	vector->capacity = new_capacity;
	return (1);
}
