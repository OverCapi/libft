/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:52:14 by llemmel           #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_converter.h"
#include "ft/ft_char.h"

static int	parse_sign(const char *nptr, int *i)
{
	int	sign;

	sign = 1;
	while (ft_iswhite_space(nptr[*i]))
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

/*
** Convert nptr to an int stored in *out.
** Return 1 on success, 0 if nptr is not a whole valid int
** (no digit, trailing characters or overflow).
*/
int	ft_atoi_safe(const char *nptr, int *out)
{
	long	nb;
	int		sign;
	int		i;

	if (!nptr || !out)
		return (0);
	nb = 0;
	i = 0;
	sign = parse_sign(nptr, &i);
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + (nptr[i++] - '0');
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (0);
	}
	if (nptr[i] != '\0')
		return (0);
	*out = (int)(nb * sign);
	return (1);
}
