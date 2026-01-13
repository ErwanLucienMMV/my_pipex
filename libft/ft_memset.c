/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:41:41 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/13 11:41:29 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = c;
		i++;
	}
	return (s);
}

/*int	main()
{
	char	coucou [] = {'1', '2', '3', '4', '5'};
	ft_memset(coucou, 'c', 5);
	printf("%s", coucou);
	return (1);
}*/
