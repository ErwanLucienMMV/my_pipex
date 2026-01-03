/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:25:02 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/03 15:06:41 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

char	*ft_copy_nl(char *tocopy)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (!tocopy)
		return (NULL);
	len = find_nl(tocopy);
	if (len != -1)
	{
		res = malloc(sizeof(char) * (len + 2));
		if (!res)
			return (NULL);
		while (tocopy[i] != '\n' && i < len)
		{
			res[i] = tocopy[i];
			i++;
		}
		if (tocopy[i] == '\n')
			res[i++] = '\n';
		res[i] = '\0';
	}
	else
		res = ft_strdup(tocopy);
	return (res);
}

char	*keep_after_nl(char *s)
{
	char	*res;
	ssize_t	start;

	start = find_nl(s);
	res = NULL;
	if (start == -1 || s[start +1] == '\0')
	{
		free(s);
		return (NULL);
	}
	else if (start != -1)
		res = ft_strdup((char *)(s + start + 1));
	free(s);
	return (res);
}

char	*ft_concat(char *s1, char*s2)
{
	char	*res;

	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (NULL);
	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static	void	free_the_stuff(char *temp[1024])
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (temp[i])
		{
			free(temp[i]);
			temp[i] = NULL;
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*temp[1024];
	char		*temp2;
	int			howmuch;

	if (fd == -1)
		return (free_the_stuff(temp), NULL);
	howmuch = 1;
	while (howmuch > 0)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (free(temp[fd]), temp[fd] = NULL, NULL);
		howmuch = read(fd, buff, BUFFER_SIZE);
		temp[fd] = fillthetemp(buff, temp[fd], howmuch);
		if (!temp[fd] || find_nl(temp[fd]) != -1)
			break ;
	}
	if ((temp[fd] && find_nl(temp[fd]) != -1) || (temp[fd] && temp[fd][0]))
	{
		temp2 = ft_copy_nl(temp[fd]);
		if (temp2)
			return (temp[fd] = keep_after_nl(temp[fd]), temp2);
	}
	return (free(temp[fd]), temp[fd] = NULL, NULL);
}
