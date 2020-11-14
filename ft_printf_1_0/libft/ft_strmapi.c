/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:37:51 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/01 19:04:10 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	s_len;

	if (!s || !f)
		return (0);
	s_len = ft_strlen((char*)s);
	res = (char*)malloc(s_len + 1);
	if (!res)
		return (0);
	res[s_len] = '\0';
	while (s_len--)
		res[s_len] = f(s_len, s[s_len]);
	return (res);
}
