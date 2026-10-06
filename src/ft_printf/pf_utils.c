/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:39:35 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:42:35 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

/*
** Write nb in base into the end of buf (PF_BUF_SIZE bytes).
** Return a pointer on the first digit.
** With a precision of 0, the value 0 gives an empty string.
*/
char	*pf_utoa_base(unsigned long nb, const char *base, char *buf,
		int precision)
{
	unsigned long	base_len;
	int				i;

	i = PF_BUF_SIZE - 1;
	buf[i] = '\0';
	if (nb == 0 && precision == 0)
		return (buf + i);
	base_len = ft_strlen(base);
	buf[--i] = base[nb % base_len];
	nb /= base_len;
	while (nb)
	{
		buf[--i] = base[nb % base_len];
		nb /= base_len;
	}
	return (buf + i);
}

/*
** Fetch the argument of a d/i conversion : ssize_t with 'z', int otherwise.
*/
long	pf_arg_signed(t_spec *spec, va_list *ap)
{
	if (spec->size_t_len)
		return (va_arg(*ap, ssize_t));
	return (va_arg(*ap, int));
}

/*
** Fetch the argument of a u/x/X conversion :
** size_t with 'z', unsigned int otherwise.
*/
size_t	pf_arg_unsigned(t_spec *spec, va_list *ap)
{
	if (spec->size_t_len)
		return (va_arg(*ap, size_t));
	return (va_arg(*ap, unsigned int));
}
