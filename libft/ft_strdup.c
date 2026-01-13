/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:40:47 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/12 15:58:58 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source )
{
	size_t	i;
	char	*res;

	i = ft_strlen(source);
	if (!source)
		return (NULL);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i = 0;
	while (source[i])
	{
		res[i] = *(char *)(source + i);
		i++;
	}
	return (res);
}
