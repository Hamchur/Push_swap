/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:42:32 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/04 16:58:45 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	int				index;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_all
{
	int				min;
	int				med;
	int				max;
	int				min_a;
	int				size_a;
	int				size_b;
	t_node			*stack_a;
	t_node			*stack_b;
}					t_all;

t_all	*parser(char **argv);
void	sort(t_all *all);

void	add(t_all *all, char **arr);
void	bubble_sort(t_all *all, int *sort, int *not_sort, int len);
void	create_stack(t_all *all, int *sort, int *not_sort, int len);

void	error(void);
void	free_arr(char **arr, int flag);
void	checking_arr(char **arr);
char	**get_line(char **argv);
void	repeat(char **arr);

t_all	*init(char **arr);
t_node	*new_list(int num, int index);
void	lstadd_back(t_node **stack_a, t_node *new);
void	free_stack(t_all *all);

void	push_a(t_all *all);
void	push_b(t_all *all);
void	pa(t_all *all, int flag);
void	pb(t_all *all, int flag);

void	rra(t_all *all, int flag);
void	rrb(t_all *all, int flag);
void	rrr(t_all *all, int flag);

void	ra(t_all *all, int flag);
void	rb(t_all *all, int flag);
void	rr(t_all *all, int flag);

void	sa(t_all *all, int flag);
void	sb(t_all *all, int flag);
void	ss(t_all *all, int flag);

int		is_sorted(t_all *all);
void	sort3a(t_all *all);
void	sort3b(t_all *all);
int		short_cut(t_all *all);
void	sort5(t_all *all);

void	move_down(t_all *all);
void	extremums_a(t_all *all);
void	extremums_b(t_all *all);
void	move_ab1(t_all *all);

void	push_down(t_all *all);
void	min_ab(t_all *all);
int		min_ba(t_all *all);
void	move_ab(t_all *all);
void	move_ba(t_all *all);

void	norm(t_all *all, int flag);
void	norm2(t_all *all, int flag);
void	sort_ab3(t_all *all);
void	sort_ab5(t_all *all, int flag, int min, int i);
void	sort_ba5(t_all *all);

#endif
