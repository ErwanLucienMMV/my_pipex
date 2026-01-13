/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:20:11 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/13 12:09:44 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src [i];
		i ++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*int	main()
{
	char coucou [] = "coucou";
	char boubou [] = "boubou";

	strlcpy(boubou, coucou, 6);
	printf("%s", boubou);
	return (1);
}*/
