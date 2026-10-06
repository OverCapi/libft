/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:39:35 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:39:35 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	pf_write(t_out *out, const char *s, int len)
{
	if (len <= 0 || out->error)
		return ;
	if (write(out->fd, s, len) < 0)
	{
		out->error = 1;
		return ;
	}
	out->len += len;
}

void	pf_pad(t_out *out, char c, int n)
{
	char	buf[64];
	int		chunk;

	ft_memset(buf, c, sizeof(buf));
	while (n > 0)
	{
		chunk = n;
		if (chunk > (int) sizeof(buf))
			chunk = sizeof(buf);
		pf_write(out, buf, chunk);
		n -= chunk;
	}
}

void	pf_print_text(t_out *out, t_spec *spec, const char *s, int len)
{
	if (!spec->minus)
		pf_pad(out, ' ', spec->width - len);
	pf_write(out, s, len);
	if (spec->minus)
		pf_pad(out, ' ', spec->width - len);
}

/*
** Layout : [spaces][prefix][zeros][digits][spaces if '-']
** zeros come from the precision, or from the '0' flag when
** there is no precision and no '-'.
*/
void	pf_print_number(t_out *out, t_spec *spec, const char *prefix,
		const char *digits)
{
	int	digits_len;
	int	prefix_len;
	int	zeros;
	int	total;

	digits_len = ft_strlen(digits);
	prefix_len = ft_strlen(prefix);
	zeros = 0;
	if (spec->precision > digits_len)
		zeros = spec->precision - digits_len;
	else if (spec->zero && !spec->minus && spec->precision < 0)
		zeros = spec->width - prefix_len - digits_len;
	if (zeros < 0)
		zeros = 0;
	total = prefix_len + zeros + digits_len;
	if (!spec->minus)
		pf_pad(out, ' ', spec->width - total);
	pf_write(out, prefix, prefix_len);
	pf_pad(out, '0', zeros);
	pf_write(out, digits, digits_len);
	if (spec->minus)
		pf_pad(out, ' ', spec->width - total);
}
