/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:34:39 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/03 19:21:32 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		res = (char*)malloc(1);
		res[0] = '\0';
		return (res);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (!(res = (char*)malloc(len + 1)))
		return (0);
	res[len] = '\0';
	start = start + len - 1;
	while (len--)
		res[len] = s[start--];
	return (res);
}
