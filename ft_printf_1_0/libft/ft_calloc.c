/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:14:38 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/10 20:54:46 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*res;
	unsigned char	*cres;
	size_t			bytes;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	bytes = count * size;
	res = (void*)malloc(bytes);
	if (!res)
		return (0);
	cres = res;
	while (bytes--)
		cres[bytes] = 0;
	return (res);
}
