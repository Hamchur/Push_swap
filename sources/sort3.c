/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:13:56 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/04 17:13:59 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	norm(t_all *all, int flag)
{
	sort_ab3(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag != flag)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1)
		push_down(all);
}

void	norm2(t_all *all, int flag)
{
	sort_ab3(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag == -1)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1 && \
			all->stack_a->index +1 == all->stack_a->prev->index)
		push_down(all);
}

void	sort_ab3(t_all *all)
{
	int	a;
	int	b;
	int	c;

	if (all->size_b == 0)
		return ;
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	c = all->stack_b->prev->index;
	if (b > a && b > c)
		rrb(all, 1);
	else if (a > b && a > c)
		rb(all, 1);
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	if (a > b)
		sb(all, 1);
}

void	sort_ab5(t_all *all, int flag, int min, int i)
{
	t_node	*tmp;

	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	tmp = all->stack_a;
	while (tmp->flag == flag && flag != -1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 5)
	{
		while (i > 2)
		{
			if (all->stack_a->index == min)
			{
				push_down(all);
				min++;
			}
			else
				pb(all, 1);
			i--;
		}
		norm(all, flag);
	}
}

void	sort_ba5(t_all *all)
{
	int		flag;
	int		min;
	int		i;

	i = all->size_b;
	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	while (i > 3)
	{
		if (all->stack_b->index == min)
		{
			pa(all, 1);
			push_down(all);
			min++;
		}
		else
			pa(all, 1);
		i--;
	}
	norm2(all, flag);
}
