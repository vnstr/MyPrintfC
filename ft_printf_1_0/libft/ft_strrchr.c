/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:52:06 by gdrive            #+#    #+#             */
/*   Updated: 2020/10/30 17:18:23 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cs;
	size_t	len_s;

	len_s = 0;
	cs = (char*)s;
	len_s = ft_strlen(s);
	while (len_s + 1)
	{
		if (cs[len_s] == c)
			return (cs + len_s);
		len_s--;
	}
	return (0);
}
