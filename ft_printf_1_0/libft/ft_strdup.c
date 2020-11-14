/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:29:10 by gdrive            #+#    #+#             */
/*   Updated: 2020/10/31 17:52:16 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	bytes;
	char	*cs1;
	char	*res;

	bytes = ft_strlen(s1);
	cs1 = (char*)s1;
	res = (char*)malloc(bytes + 1);
	if (!res)
		return (0);
	res[bytes] = '\0';
	while (bytes--)
		res[bytes] = cs1[bytes];
	return (res);
}
