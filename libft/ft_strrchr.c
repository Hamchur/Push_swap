/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:17:46 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:17:51 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
