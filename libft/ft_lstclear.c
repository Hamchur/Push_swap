/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:09:19 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:09:23 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old_elem;

	if (!*lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		old_elem = *lst;
		*lst = old_elem->next;
		free(old_elem);
	}
	*lst = NULL;
}
