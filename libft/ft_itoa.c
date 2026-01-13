/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:19:22 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/12 19:23:19 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "stddef.h"
#include "unistd.h"

static size_t	get_size(long nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
	{
		size += 1;
		nb = -nb;
	}
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			size += 1;
			nb /= 10;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	is_negative;
	size_t	size;
	long	nb;
	char	*res;

	size = get_size((long) n);
	is_negative = 0;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	nb = (long) n;
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
		is_negative = 1;
	}
	res[size] = '\0';
	while (size > (size_t) is_negative)
	{
		res[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (res);
}
