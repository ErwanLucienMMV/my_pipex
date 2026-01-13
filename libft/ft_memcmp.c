/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:26:22 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/13 13:06:49 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size )
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		if (*(unsigned char *)(pointer1 + i)
				!= *(unsigned char *)(pointer2 + i))
			return (*(unsigned char *)(pointer1 + i)
					- *(unsigned char *)(pointer2 + i));
		i++;
	}
	return (*(unsigned char *)(pointer1 + i)
			- *(unsigned char *)(pointer2 + i));
}
