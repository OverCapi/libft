/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:16:58 by capi              #+#    #+#             */
/*   Updated: 2026/10/06 22:16:58 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
# define FT_EXIT_H

# include <stdlib.h>

void	exit_error(char *error_msg, int exit_status);
void	exit_free(char *error_msg, void *ptr, int exit_status);

#endif
