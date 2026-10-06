/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:00:00 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 21:55:59 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERTER_H
# define FT_CONVERTER_H

# include <stdlib.h>
# include <limits.h>

int		ft_atoi_safe(const char *nptr, int *out);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

#endif
