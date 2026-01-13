/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:25:48 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/13 11:21:12 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*pointer;

	if (size != 0 && count > ((size_t) -1 / size))
		return (NULL);
	pointer = (void *)malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*(unsigned char *)(pointer + i) = 0;
		i++;
	}
	return (pointer);
}
