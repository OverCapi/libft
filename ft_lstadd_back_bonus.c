/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:14:26 by llemmel           #+#    #+#             */
/*   Updated: 2024/10/19 14:33:49 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	if (!(*lst) && !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		lstlast = ft_lstlast(*lst);
		lstlast->next = new;
	}
}
