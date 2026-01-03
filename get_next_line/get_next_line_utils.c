/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:33:19 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/03 15:06:33 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len1;
	size_t		len2;
	char		*res;

	i = 0;
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
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

char	*ft_strdup(const char *source )
{
	size_t		i;
	char		*res;

	if (!source)
		return (NULL);
	i = ft_strlen((char *)source);
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

ssize_t	find_nl(const char *s)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (-2);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*fillthetemp(char *buff, char *temp, int howmuch)
{
	char	*res;

	if (howmuch < 0)
	{
		free(buff);
		return (temp);
	}
	buff[howmuch] = '\0';
	res = ft_concat(temp, buff);
	free(buff);
	return (res);
}
