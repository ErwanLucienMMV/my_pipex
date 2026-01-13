/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:12:57 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/12 15:19:58 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int search)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == search % 256)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == search % 256)
		return ((char *)(string + i));
	return (NULL);
}
