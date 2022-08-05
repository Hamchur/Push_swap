/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:13:50 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/04 17:13:52 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_down(t_all *all)
{
	all->stack_a->flag = -1;
	ra(all, 1);
}

void	min_ab(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_b->next->index == min)
	{
		sb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_b->prev->index == min)
	{
		rrb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
}

int	min_ba(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down(all);
		return (1);
	}
	else if (all->stack_a->index == min)
		push_down(all);
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
	return (0);
}

void	move_ab(t_all *all)
{
	int	flag;
	int	min;

	flag = all->stack_a->flag;
	while (all->stack_a->flag == flag && flag != -1)
	{
		min = all->stack_a->prev->index + 1;
		if (all->size_b > 1)
			min_ab(all);
		if (all->stack_a->index == min)
			push_down(all);
		else
			pb(all, 1);
	}
}

void	move_ba(t_all *all)
{
	int	i;

	extremums_b(all);
	i = all->size_b;
	while (i-- > 0)
	{
		if (min_ba(all))
			continue ;
		if (all->stack_b->index > all->med)
		{
			all->stack_b->flag++;
			pa(all, 1);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}
