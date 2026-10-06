/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:00:00 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 21:57:15 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>

# define VECTOR_MIN_CAPACITY 8

/*
** Dynamic array of elements of elem_size bytes.
** len and capacity are counted in elements, not bytes.
** Functions returning int return 1 on success, 0 on failure.
*/
typedef struct s_vector
{
	void	*data;
	size_t	len;
	size_t	capacity;
	size_t	elem_size;
}	t_vector;

t_vector	*ft_vector_new(size_t capacity, size_t elem_size);
int			ft_vector_reserve(t_vector *vector, size_t new_capacity);
int			ft_vector_add(t_vector *vector, const void *elem);
int			ft_vector_insert(t_vector *vector, const void *elem, size_t index);
void		ft_vector_rm(t_vector *vector, size_t index);
void		*ft_vector_get(t_vector *vector, size_t index);
void		ft_vector_free(t_vector *vector);

#endif
