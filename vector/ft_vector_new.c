/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:28:18 by capi              #+#    #+#             */
/*   Updated: 2025/07/05 12:25:33 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector	*ft_vector_new(size_t size, size_t data_size)
{
	t_vector	*vector;
	
	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->data = ft_calloc(size, sizeof(void *));
	if (!vector->data)
		return (free(vector), NULL);
	vector->len = 0;
	vector->max_size = size;
	vector->data_size = data_size;
	return (vector);
}
