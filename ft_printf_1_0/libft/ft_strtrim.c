/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:29:21 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/02 18:50:28 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;
	char	*res_begin;

	if (!s1)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	start = (char*)s1;
	while (*s1)
		s1++;
	s1--;
	while (s1 > start && ft_strchr(set, *s1))
		s1--;
	end = (char*)s1;
	if (!(res = (char*)malloc(end - start + 2)))
		return (0);
	res_begin = res;
	while (start <= end)
		*res++ = *start++;
	*res = '\0';
	return (res_begin);
}
