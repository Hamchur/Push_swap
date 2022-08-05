/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:17:06 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:17:09 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*(ptr + i) == *(ptr2 + i) && (i < n - 1) && *(ptr + i))
		i++;
	return (*(ptr + i) - *(ptr2 + i));
}
