/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:45:11 by llemmel           #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	char_converter(unsigned char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	str_converter(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ptr_converter(size_t addr)
{
	if (!addr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	pf_putnbr_base(addr, HEX_LOWER);
	return (2 + pf_nbrlen_base(addr, 16));
}

int	dec_converter(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
		len = 1;
	}
	pf_putnbr_base(nb, DECIMAL);
	return (len + pf_nbrlen_base(nb, 10));
}

int	hex_converter(unsigned int nb, int upper)
{
	if (upper)
		pf_putnbr_base(nb, HEX_UPPER);
	else
		pf_putnbr_base(nb, HEX_LOWER);
	return (pf_nbrlen_base(nb, 16));
}
