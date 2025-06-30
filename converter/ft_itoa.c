/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:23 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/30 14:04:55 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	size_n(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*nb_str;
	size_t	str_size;

	str_size = size_n(n);
	nb_str = (char *)malloc((str_size + 1) * sizeof(char));
	if (nb_str == NULL)
		return (NULL);
	nb_str[str_size] = '\0';
	if (n == 0)
		nb_str[--str_size] = '0';
	if (n < 0)
		nb_str[0] = '-';
	while (n != 0)
	{
		if (n % 10 < 0)
			nb_str[str_size - 1] = '0' + -(n % 10);
		else
			nb_str[str_size - 1] = '0' + (n % 10);
		n /= 10;
		str_size--;
	}
	return (nb_str);
}
