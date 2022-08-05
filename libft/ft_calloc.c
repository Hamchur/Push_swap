/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:06:41 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:06:46 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	ret = malloc(size * count);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, size * count);
	return ((void *)ret);
}
