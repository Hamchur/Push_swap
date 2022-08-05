/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:10:48 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:10:52 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(sizeof(*mem) * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
