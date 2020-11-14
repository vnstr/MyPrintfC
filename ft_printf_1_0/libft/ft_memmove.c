/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:48:53 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/02 18:28:28 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	csrc = (unsigned char*)src;
	cdest = (unsigned char*)dst;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		cdest += len - 1;
		csrc += len - 1;
		while (len--)
			*cdest-- = *csrc--;
		return (dst);
	}
	while (len--)
		*cdest++ = *csrc++;
	return (dst);
}
