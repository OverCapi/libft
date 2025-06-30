/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:26:50 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/30 14:04:55 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

/* CONVERTER UTILS */
int		get_dec_size(unsigned int nb, int sign);
void	ft_putunbr(unsigned int nbr);
int		get_hex_size(size_t nb);
void	ft_puthexa(size_t nb, int maj);

/* CONVERTER */
int		char_converter(unsigned char c);
int		str_converter(char *str);
int		ptr_converter(size_t addr);
int		dec_converter(unsigned int nb, int sign);
int		hex_converter(unsigned int nb, int maj);

int		ft_printf(const char *format, ...);

#endif