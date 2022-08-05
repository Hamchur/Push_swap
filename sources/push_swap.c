/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:13:24 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/04 19:53:11 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_all	*parser(char **argv)
{
	t_all	*all;
	char	**arr;

	arr = get_line(argv);
	checking_arr(arr);
	repeat(arr);
	all = init(arr);
	add(all, arr);
	free_arr(arr, 0);
	return (all);
}

void	sort(t_all *all)
{
	if (is_sorted(all))
		free_stack(all);
	if (all->size_a < 6)
	{
		sort5(all);
		free_stack(all);
	}
	move_ab1(all);
	while (!(is_sorted(all) && all->size_b == 0))
	{
		if (all->size_b > 0 && all->size_b < 6)
			sort_ba5(all);
		else if (all->size_b >= 6)
			move_ba(all);
		if (all->size_b == 0)
		{
			sort_ab5(all, 0, 0, 0);
			move_ab(all);
		}
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc > 1)
	{
		all = parser(argv);
		sort(all);
		free_stack(all);
	}
	return (0);
}
