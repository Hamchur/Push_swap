/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:12:38 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:12:41 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_reverse_list(t_list *list)
{
	if (list)
	{
		ft_print_reverse_list(list->next);
		ft_putendl_fd(list->content, 1);
	}
}
