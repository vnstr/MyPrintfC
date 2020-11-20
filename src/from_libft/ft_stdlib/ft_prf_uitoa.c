/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_uitoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:45:11 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 00:42:24 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function works like itoa (man itoa),
**	but takes unsigned int32.
*/

#include <stdio.h>
#include "ft_printf.h"

static size_t	ft_uitoa_lennb(uint32_t n)
{
	size_t	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_prf_uitoa(uint32_t n)
{
	char		*res;
	size_t		nb_len;

	nb_len = ft_uitoa_lennb(n);
	if ((res = (char*)malloc(sizeof(char) * (nb_len + 1))) == NULL)
		return (NULL);
	res[nb_len] = '\0';
	while (nb_len-- != 0)
	{
		res[nb_len] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
