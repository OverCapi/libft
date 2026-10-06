/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:23:40 by llemmel           #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	convert(va_list *ap, char spec)
{
	if (spec == 'c')
		return (char_converter((unsigned char)va_arg(*ap, int)));
	if (spec == 's')
		return (str_converter(va_arg(*ap, char *)));
	if (spec == 'p')
		return (ptr_converter((size_t)va_arg(*ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (dec_converter(va_arg(*ap, int)));
	if (spec == 'u')
		return (dec_converter(va_arg(*ap, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (hex_converter(va_arg(*ap, unsigned int), spec == 'X'));
	if (spec == '%')
		return (char_converter('%'));
	char_converter('%');
	return (1 + char_converter(spec));
}

static size_t	print_text(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '%')
		len++;
	write(1, str, len);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;
	size_t	text_len;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!format[1])
				return (va_end(ap), -1);
			len += convert(&ap, format[1]);
			format += 2;
			continue ;
		}
		text_len = print_text(format);
		len += text_len;
		format += text_len;
	}
	va_end(ap);
	return (len);
}
