/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:27:02 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 00:43:49 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function works like itoa (man itoa).
*/

#include <stdio.h>
#include "ft_printf.h"

static size_t	ft_itoa_lennb(long n)
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

static char		*put_minus_nb(char *res, int64_t n, size_t nb_len)
{
	res[0] = '-';
	while (nb_len-- > 1)
	{
		res[nb_len] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}

char			*ft_prf_itoa(int64_t n)
{
	char		*res;
	char		sign;
	size_t		nb_len;

	if (n == INT64_MIN)
		return (ft_prf_strjoin("-9223372036854775808", NULL));
	sign = 0;
	if (n < 0)
		sign = 1;
	nb_len = ft_itoa_lennb(n) + sign;
	if ((res = (char*)malloc(sizeof(char) * (nb_len + 1))) == NULL)
		return (NULL);
	res[nb_len] = '\0';
	if (n < 0)
		return (put_minus_nb(res, -n, nb_len));
	while (nb_len-- != 0)
	{
		res[nb_len] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
