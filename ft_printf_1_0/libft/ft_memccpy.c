/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:52:28 by gdrive            #+#    #+#             */
/*   Updated: 2020/10/30 16:48:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	unsigned char	cc;

	csrc = (unsigned char*)src;
	cdest = (unsigned char*)dst;
	cc = (unsigned char)c;
	while (n--)
	{
		*cdest = *csrc;
		if (*csrc == cc)
			return ((void*)(++cdest));
		cdest++;
		csrc++;
	}
	return (0);
}
