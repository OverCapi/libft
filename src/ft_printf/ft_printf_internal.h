/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:16:58 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:31:06 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft/ft_printf.h"
# include "ft/ft_str.h"
# include "ft/ft_write.h"

# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

/* CONVERTER UTILS */
int		pf_nbrlen_base(unsigned long nb, unsigned long base_len);
void	pf_putnbr_base(unsigned long nb, const char *base);

/* CONVERTER */
int		char_converter(unsigned char c);
int		str_converter(char *str);
int		ptr_converter(size_t addr);
int		dec_converter(long nb);
int		hex_converter(unsigned int nb, int upper);

#endif
