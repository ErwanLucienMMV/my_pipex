/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:36:11 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/12 19:22:50 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	i = len;
	while (i >= 0)
	{
		if (s[i] == c % 256)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	char boubou [] = "bebouuuuuu";
	printf("%s", ft_strrchr(boubou, 'o'));
	return(1);
}*/
