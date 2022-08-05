/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:13:44 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:13:48 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = n * -1;
	}
	else
		i = n;
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + 48, fd);
}
