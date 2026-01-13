/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:37:52 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/13 11:21:26 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static	int	lengthofword(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static	size_t	clearmymess(char **tab, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

static	size_t	filltab(char **tab, char const *s, char c, size_t words)
{
	size_t	wordcount;
	size_t	i;
	size_t	iterator;
	size_t	next_word_length;

	wordcount = 0;
	iterator = 0;
	while (wordcount < words)
	{
		while (s[iterator] && s[iterator] == c)
			iterator++;
		i = 0;
		next_word_length = lengthofword((s + iterator), c);
		tab[wordcount] = malloc(sizeof(char) * (next_word_length + 1));
		if (!tab[wordcount])
			return (clearmymess(tab, wordcount));
		while (i < next_word_length)
			tab[wordcount][i++] = s[iterator++];
		tab[wordcount][i] = '\0';
		wordcount ++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	failed;
	char	**tab;

	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	if (words != 0)
	{
		failed = filltab(tab, s, c, words);
		if (failed)
			return (NULL);
	}
	tab[words] = NULL;
	return (tab);
}
