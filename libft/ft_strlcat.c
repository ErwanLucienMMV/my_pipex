/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:02:27 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/11 20:33:02 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	dst_len = ft_strlen(d);
	index = dst_len;
	i = 0;
	while (s[i] && (i + index + 1) < (dstsize))
	{
		d[index + i] = s[i];
		i++;
	}
	if (i < dstsize)
		d[index + i] = '\0';
	if (dstsize <= dst_len)
		return (ft_strlen(s) + dstsize);
	return (ft_strlen(s) + dst_len);
}
//#include <stdio.h>
