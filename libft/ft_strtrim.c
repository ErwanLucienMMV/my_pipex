/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:05:01 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/09 14:26:22 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	const	*endprefix(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len_set;

	i = 0;
	len_set = ft_strlen((char *)set);
	if (!set[0])
		return (s1);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				break ;
			j++;
		}
		if (j == len_set)
		{
			return ((s1 + i));
		}
		i++;
	}
	return (s1 + i);
}

const	char	*startsuffix(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len_set;
	size_t	len_str;

	len_set = ft_strlen((char *)set);
	len_str = ft_strlen((char *)s1);
	i = 1;
	if (!set[0])
		return (s1 + len_str);
	while (i < len_str)
	{
		j = 0;
		while (set[j])
		{
			if (*(set + j) == *(s1 + len_str - i))
				break ;
			j++;
		}
		if (j == len_set)
			return ((s1 + len_str - i + 1));
		i++;
	}
	return ((s1 + i));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char const	*start;
	char const	*end;
	char		*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = endprefix(s1, set);
	end = startsuffix(s1, set);
	i = 0;
	if (!s1[0] || end < start)
		res = malloc(1);
	else
		res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	while ((start + i) < end)
	{
		*(char *)(res + i) = *(unsigned char *)(start + i);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	main()
// {
// 	printf("%s", NULL);
// 	printf("%s",ft_strtrim("", ""));
// 	return (1);
// }
