/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_rm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:12:05 by capi              #+#    #+#             */
/*   Updated: 2025/07/05 12:50:23 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vector_rm(t_vector *vector, size_t index)
{
	void	*ptr;
	
	if (!vector || index * vector->data_size >= vector->len)
		return ;
	ptr = vector->data + index * vector->data_size;
	ft_memmove(\
		ptr, ptr + vector->data_size, \
		vector->data + (vector->len * vector->data_size) - (ptr + vector->data_size));
	vector->len -= vector->data_size;
}
