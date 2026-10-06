/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:07:42 by llemmel           #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	pf_nbrlen_base(unsigned long nb, unsigned long base_len)
{
	int	len;

	len = 1;
	while (nb >= base_len)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

void	pf_putnbr_base(unsigned long nb, const char *base)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
		pf_putnbr_base(nb / base_len, base);
	ft_putchar_fd(base[nb % base_len], 1);
}
