/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:23:40 by llemmel           #+#    #+#             */
/*   Updated: 2026/10/06 22:39:35 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	pf_process(t_out *out, const char *format, va_list *ap)
{
	t_spec		spec;
	const char	*start;
	size_t		len;

	while (*format && !out->error)
	{
		len = 0;
		while (format[len] && format[len] != '%')
			len++;
		pf_write(out, format, len);
		format += len;
		if (!*format)
			break ;
		start = format;
		format = pf_parse_spec(format + 1, &spec);
		if (!spec.conv)
			return (-1);
		if (!pf_convert(out, &spec, ap))
			pf_write(out, start, format - start + 1);
		format++;
	}
	if (out->error)
		return (-1);
	return (out->len);
}

static int	pf_vdprintf(int fd, const char *format, va_list *ap)
{
	t_out	out;

	if (fd < 0 || !format)
		return (-1);
	out.fd = fd;
	out.len = 0;
	out.error = 0;
	return (pf_process(&out, format, ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = pf_vdprintf(1, format, &ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = pf_vdprintf(fd, format, &ap);
	va_end(ap);
	return (ret);
}
