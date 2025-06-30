/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:39:23 by capi              #+#    #+#             */
/*   Updated: 2025/06/30 14:04:55 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vector_reserve(t_vector *vector, size_t new_size)
{
	void	*old_data;

	if (!vector)
		return ;
	old_data = vector->data;
	vector->data = malloc(new_size);
	if (!vector->data)
	{
		vector->data = old_data;
		return ;
	}
	ft_memcpy(vector->data, old_data, vector->max_size);
	vector->max_size = new_size;
}
