/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:52:14 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/30 14:04:55 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_overflow(long int nb, int sign)
{
	if (sign == 1 && nb > INT_MAX)
		return (0);
	else if (sign == -1 && (nb < INT_MIN || nb >= INT_MAX))
		return (0);
	return (1);
}

int	ft_atoi_safe(const char *nptr)
{
	int		nb;
	int		sign;
	int		i;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_iswhite_space(nptr[i]) == 1 && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		if (!check_overflow((long int)nb * 10 + nptr[i] - '0', sign))
			return (0);
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}
