/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:13:36 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/04 20:07:22 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_all *all)
{
	int		i;
	t_node	*head;

	head = all->stack_a;
	i = all->size_a - 1;
	while (i-- > 0)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort3a(t_all *all)
{
	int	a;
	int	b;
	int	c;

	a = all->stack_a->index;
	b = all->stack_a->next->index;
	c = all->stack_a->prev->index;
	if (b > a && b > c)
		rra(all, 1);
	else if (a > b && a > c)
		ra(all, 1);
	a = all->stack_a->index;
	b = all->stack_a->next->index;
	if (a > b)
		sa(all, 1);
}

void	sort3b(t_all *all)
{
	int	a;
	int	b;
	int	c;
	int	i;

	a = all->stack_b->index;
	b = all->stack_b->next->index;
	c = all->stack_b->prev->index;
	i = all->size_b;
	if (b > a && b > c)
		rrb(all, 1);
	else if (a > b && a > c)
		rb(all, 1);
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	if (a > b)
		sb(all, 1);
	while (i-- > 0)
	{
		all->stack_b->flag = -1;
		pa(all, 1);
		ra(all, 1);
	}
}

int	short_cut(t_all *all)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = all->stack_a;
	i = 0;
	while (++i)
	{
		if (tmp->index == all->min)
			break ;
		tmp = tmp->next;
	}
	tmp = all->stack_a;
	j = 0;
	while (++j)
	{
		if (tmp->index == all->min)
			break ;
		tmp = tmp->prev;
	}
	if (j >= i)
		return (1);
	return (0);
}

void	sort5(t_all *all)
{
	while (all->size_a > 3)
	{
		extremums_a(all);
		if (all->stack_a->index == all->min)
		{
			pb(all, 1);
			continue ;
		}
		if (short_cut(all))
			ra(all, 1);
		else
			rra(all, 1);
	}
	sort3a(all);
	pa(all, 1);
	pa(all, 1);
}
