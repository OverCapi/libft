/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:16:04 by llemmel           #+#    #+#             */
/*   Updated: 2024/10/21 11:36:19 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// utiliser memset
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);

	// size_t			i;
	// unsigned char	*s2;

	// s2 = (unsigned char *)s;
	// i = 0;
	// while (i < n)
	// {
	// 	s2[i] = 0;
	// 	i++;
	// }
}
