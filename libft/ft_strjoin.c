/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:49:14 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/11 19:43:56 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*res;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	while (i < len1)
	{
		*(char *)(res + i) = *(char *)(s1 + i);
		i++;
	}
	i = 0;
	while (i < len2)
	{
		*(char *)(res + len1 + i) = *(char *)(s2 + i);
		i++;
	}
	res[len1 + len2] = '\0';
	return (res);
}
