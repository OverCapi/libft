/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:15:00 by llemmel           #+#    #+#             */
/*   Updated: 2024/10/21 11:36:57 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	// utiliser les fonction deja faite
	// return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
	// 	|| (c >= '0' && c <= '9'));
	return (ft_isalpha(c) || ft_isdigit(c));
}
