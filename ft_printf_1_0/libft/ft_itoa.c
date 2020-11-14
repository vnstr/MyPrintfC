/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:54:59 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/01 17:34:40 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_lennb(long n)
{
	size_t	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*res;
	char	*res_begin;
	size_t	nb_len;
	long	ln;

	ln = n;
	nb_len = ft_itoa_lennb(ln) + (ln < 0 ? 1 : 0);
	res = (char*)malloc(nb_len + 1);
	if (!res)
		return (0);
	res[nb_len] = '\0';
	res_begin = res;
	if (n < 0)
	{
		res[0] = '-';
		ln *= (-1);
	}
	while (nb_len-- && res[nb_len] != '-')
	{
		res[nb_len] = ln % 10 + 48;
		ln /= 10;
	}
	return (res_begin);
}
