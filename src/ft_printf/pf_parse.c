/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:39:35 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:42:35 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static const char	*parse_flags(const char *format, t_spec *spec)
{
	while (*format && ft_strchr("-0# +", *format))
	{
		if (*format == '-')
			spec->minus = 1;
		else if (*format == '0')
			spec->zero = 1;
		else if (*format == '#')
			spec->hash = 1;
		else if (*format == ' ')
			spec->space = 1;
		else
			spec->plus = 1;
		format++;
	}
	return (format);
}

static const char	*parse_number(const char *format, int *nb)
{
	*nb = 0;
	while (ft_isdigit(*format))
	{
		if (*nb < 100000000)
			*nb = *nb * 10 + (*format - '0');
		format++;
	}
	return (format);
}

/*
** Parse the spec following a '%'.
** Return a pointer on the conversion character (spec->conv).
*/
const char	*pf_parse_spec(const char *format, t_spec *spec)
{
	ft_bzero(spec, sizeof(t_spec));
	spec->precision = -1;
	format = parse_flags(format, spec);
	format = parse_number(format, &spec->width);
	if (*format == '.')
		format = parse_number(format + 1, &spec->precision);
	if (*format == 'z')
	{
		spec->size_t_len = 1;
		format++;
	}
	spec->conv = *format;
	return (format);
}
