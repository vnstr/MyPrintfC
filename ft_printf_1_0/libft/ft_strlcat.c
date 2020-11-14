/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 12:26:26 by gdrive            #+#    #+#             */
/*   Updated: 2020/10/30 16:52:31 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*csrc;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	csrc = (char*)src;
	if (dstsize == 0)
		return (ft_strlen(csrc));
	if (dstsize <= len_dst)
		return (ft_strlen(csrc) + dstsize);
	while (*dst)
	{
		dstsize--;
		dst++;
	}
	while (dstsize-- > 1 && *csrc)
		*dst++ = *csrc++;
	*dst = '\0';
	return (len_dst + ft_strlen(src));
}
