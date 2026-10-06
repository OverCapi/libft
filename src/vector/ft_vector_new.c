/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:28:18 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"

t_vector	*ft_vector_new(size_t capacity, size_t elem_size)
{
	t_vector	*vector;

	if (elem_size == 0)
		return (NULL);
	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->data = NULL;
	vector->len = 0;
	vector->capacity = 0;
	vector->elem_size = elem_size;
	if (!ft_vector_reserve(vector, capacity))
		return (free(vector), NULL);
	return (vector);
}
