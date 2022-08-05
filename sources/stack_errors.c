/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:14:17 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/04 17:44:22 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_SUCCESS);
}

void	free_arr(char **arr, int flag)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	if (flag)
		error();
}

void	checking_arr(char **arr)
{
	int			i;
	int			j;
	long long	num;

	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-')
				j++;
			if (!(ft_isdigit(arr[i][j])))
				free_arr(arr, 1);
			j++;
		}
		num = ft_atoi(arr[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_arr(arr, 1);
		}
	}
}

char	**get_line(char **av)
{
	int		i;
	char	*line;
	char	*tmp;
	char	**arr;

	line = ft_strdup(av[1]);
	i = 1;
	while (av[++i])
	{
		tmp = line;
		line = ft_strjoin(line, " ");
		free(tmp);
		tmp = line;
		line = ft_strjoin(line, av[i]);
		free(tmp);
	}
	arr = ft_split(line, ' ');
	free(line);
	return (arr);
}

void	repeat(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				free_arr(arr, 1);
			j++;
		}
		i++;
	}
}
