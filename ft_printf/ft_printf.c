/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:23:40 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/29 16:09:39 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_converter(va_list *ptr, char specifier)
{
	size_t	len;

	len = 0;
	if (specifier == 'c')
		return (char_converter((unsigned char)va_arg(*ptr, int)));
	else if (specifier == 's')
		return (str_converter(va_arg(*ptr, char *)));
	else if (specifier == 'p')
		return (ptr_converter((size_t)va_arg(*ptr, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (dec_converter(va_arg(*ptr, int), 1));
	else if (specifier == 'u')
		return (dec_converter(va_arg(*ptr, unsigned int), 0));
	else if (specifier == 'x')
		return (hex_converter(va_arg(*ptr, unsigned int), 0));
	else if (specifier == 'X')
		return (hex_converter(va_arg(*ptr, unsigned int), 1));
	else if (specifier == '%')
		return (char_converter('%'));
	else
		return (-1);
	return (len);
}

static int	check_convert(va_list *ptr, char specifier, char ** format, size_t *len)
{
	if (!specifier)
		return (-1);
	else if (!ft_strchr("cspdiuxX%", specifier))
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(specifier, 1);
		*len += 2;
		(*format)++;
	}
	else
	{
		*len += ft_converter(ptr, specifier);
		(*format)++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	len;
	size_t	write_size;
	char	*pos;
	va_list	ptr;

	if (!format)
		return (-1);
	va_start(ptr, format);
	len = 0;
	while (*format)
	{
		pos = ft_strchr(format, '%');
		if (pos)
		{
			write_size = pos - (format);
			if (write_size && write(1, format, write_size) == -1)
				return (va_end(ptr), -1);
			len += write_size;
			if (check_convert(&ptr, pos[1], (char **)&format, &len) != 0)
				return (va_end(ptr), -1);
			format++;
		}
		else
		{
			ft_putstr_fd((char *)(format), 1);
			write_size = ft_strlen(format);
			len += write_size;
		}
		format += write_size;
	}
	va_end(ptr);
	return (len);
}
