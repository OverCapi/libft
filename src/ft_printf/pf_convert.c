/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:39:35 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:42:35 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	conv_str(t_out *out, t_spec *spec, const char *s)
{
	int	len;

	if (!s && spec->precision >= 0 && spec->precision < 6)
		s = "";
	else if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (spec->precision >= 0 && spec->precision < len)
		len = spec->precision;
	pf_print_text(out, spec, s, len);
}

static void	conv_signed(t_out *out, t_spec *spec, long nb)
{
	char			buf[PF_BUF_SIZE];
	char			*prefix;
	unsigned long	abs;

	prefix = "";
	if (nb < 0)
		prefix = "-";
	else if (spec->plus)
		prefix = "+";
	else if (spec->space)
		prefix = " ";
	abs = nb;
	if (nb < 0)
		abs = -(unsigned long)nb;
	pf_print_number(out, spec, prefix,
		pf_utoa_base(abs, DECIMAL, buf, spec->precision));
}

static void	conv_unsigned(t_out *out, t_spec *spec, unsigned long nb)
{
	char	buf[PF_BUF_SIZE];
	char	*prefix;
	char	*base;

	prefix = "";
	base = DECIMAL;
	if (spec->conv == 'x' || spec->conv == 'p')
		base = HEX_LOWER;
	else if (spec->conv == 'X')
		base = HEX_UPPER;
	if (spec->conv == 'p' || (spec->hash && nb && spec->conv == 'x'))
		prefix = "0x";
	else if (spec->hash && nb && spec->conv == 'X')
		prefix = "0X";
	pf_print_number(out, spec, prefix,
		pf_utoa_base(nb, base, buf, spec->precision));
}

static void	conv_ptr(t_out *out, t_spec *spec, void *ptr)
{
	if (!ptr)
		pf_print_text(out, spec, "(nil)", 5);
	else
		conv_unsigned(out, spec, (unsigned long)ptr);
}

/*
** Print one conversion. Return 0 if spec->conv is unknown.
*/
int	pf_convert(t_out *out, t_spec *spec, va_list *ap)
{
	char	c;

	if (spec->conv == 'c')
	{
		c = (char)va_arg(*ap, int);
		pf_print_text(out, spec, &c, 1);
	}
	else if (spec->conv == 's')
		conv_str(out, spec, va_arg(*ap, char *));
	else if (spec->conv == 'd' || spec->conv == 'i')
		conv_signed(out, spec, pf_arg_signed(spec, ap));
	else if (spec->conv == 'u' || spec->conv == 'x' || spec->conv == 'X')
		conv_unsigned(out, spec, pf_arg_unsigned(spec, ap));
	else if (spec->conv == 'p')
		conv_ptr(out, spec, va_arg(*ap, void *));
	else if (spec->conv == '%')
		pf_write(out, "%", 1);
	else
		return (0);
	return (1);
}
