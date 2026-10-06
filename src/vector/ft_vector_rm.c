/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_rm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:12:05 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"
#include "ft/ft_mem.h"

void	ft_vector_rm(t_vector *vector, size_t index)
{
	unsigned char	*pos;

	if (!vector || index >= vector->len)
		return ;
	pos = (unsigned char *)vector->data + index * vector->elem_size;
	ft_memmove(pos, pos + vector->elem_size,
		(vector->len - index - 1) * vector->elem_size);
	vector->len--;
}
