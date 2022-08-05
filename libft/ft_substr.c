/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:18:07 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:18:10 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (len > 0)
	{
		ret[i] = s[start];
		i++;
		start++;
		len--;
	}
	ret[i] = '\0';
	return (ret);
}
