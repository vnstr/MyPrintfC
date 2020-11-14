/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:26:03 by gdrive            #+#    #+#             */
/*   Updated: 2020/10/30 18:22:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*chaystack;
	char	*cneedle;
	size_t	len_needle;

	chaystack = (char*)haystack;
	cneedle = (char*)needle;
	len_needle = ft_strlen(needle);
	if (!len_needle)
		return (chaystack);
	while (*chaystack && len_needle <= len--)
	{
		if (*chaystack == *cneedle)
		{
			if (!ft_memcmp(chaystack, cneedle, len_needle))
				return (chaystack);
		}
		chaystack++;
	}
	return (0);
}
