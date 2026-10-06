/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:16:58 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:42:35 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft/ft_printf.h"
# include "ft/ft_str.h"
# include "ft/ft_mem.h"
# include "ft/ft_char.h"

# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define PF_BUF_SIZE 65

/* One conversion : %[flags][width][.precision][z]conv */
typedef struct s_spec
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	int		size_t_len;
	char	conv;
}	t_spec;

/* Output state : destination fd, characters written, write error */
typedef struct s_out
{
	int	fd;
	int	len;
	int	error;
}	t_out;

/* pf_parse.c */
const char	*pf_parse_spec(const char *format, t_spec *spec);

/* pf_convert.c */
int			pf_convert(t_out *out, t_spec *spec, va_list *ap);

/* pf_output.c */
void		pf_write(t_out *out, const char *s, int len);
void		pf_pad(t_out *out, char c, int n);
void		pf_print_text(t_out *out, t_spec *spec, const char *s, int len);
void		pf_print_number(t_out *out, t_spec *spec, const char *prefix,
				const char *digits);

/* pf_utils.c */
char		*pf_utoa_base(unsigned long nb, const char *base, char *buf,
				int precision);
long		pf_arg_signed(t_spec *spec, va_list *ap);
size_t		pf_arg_unsigned(t_spec *spec, va_list *ap);

#endif
