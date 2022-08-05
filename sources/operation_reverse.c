/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:12:53 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/04 17:12:55 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_all *all, int flag)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->prev;
	if (flag)
		write (1, "rra\n", 4);
}

void	rrb(t_all *all, int flag)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->prev;
	if (flag)
		write (1, "rrb\n", 4);
}

void	rrr(t_all *all, int flag)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		rra(all, 0);
		rrb(all, 0);
		if (flag)
			write (1, "rrr\n", 4);
	}
}
