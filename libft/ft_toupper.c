/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:00:45 by emaigne           #+#    #+#             */
/*   Updated: 2025/11/10 14:07:51 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
		character -= 32;
	return (character);
}

//#include <stdio.h>
