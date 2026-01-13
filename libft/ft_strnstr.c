/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:45:31 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/12 19:22:01 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_l;
	size_t	i;
	size_t	j;

	if (!big && !little)
		return (NULL);
	len_l = ft_strlen(little);
	if (len_l == 0)
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j]
			&& (i + j) < len)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
