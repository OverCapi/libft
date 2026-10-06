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

# include <stddef.h>

typedef struct s_vector
{
	void	*data;
	size_t	len;
	size_t	max_size;
	size_t	data_size;
}	t_vector;

t_vector	*ft_vector_new(size_t size, size_t data_size);
void		ft_vector_reserve(t_vector *vector, size_t new_size);
void		ft_vector_free(t_vector *vector);
void		ft_vector_add(t_vector *vector, void *data);
void		ft_vector_rm(t_vector *vector, size_t index);
void		ft_vector_insert(t_vector *vector, void *data, size_t index);

#endif
