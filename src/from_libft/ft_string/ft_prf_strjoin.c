/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:53:07 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 00:46:11 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function works like strjoin (man strjoin),
**	but before return, function frees s2.
*/

#include "ft_printf.h"

static void	take_lens(char *s1, size_t *s1_len, char *s2, size_t *s2_len)
{
	if (s1 != NULL)
		*s1_len = ft_prf_strlen(s1);
	else
		*s1_len = 0;
	if (s2 != NULL)
		*s2_len = ft_prf_strlen(s2);
	else
		*s2_len = 0;
}

char		*ft_prf_strjoin(char const *s1, char const *s2)
{
	char		*res;
	char		*res_begin;
	const char	*save_s2;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 && !s2)
		return (0);
	take_lens((char*)s1, &s1_len, (char*)s2, &s2_len);
	if ((res = (char*)malloc(s1_len + s2_len + 1)) == NULL)
	{
		if (s2 != NULL)
			free((char*)s2);
		return (NULL);
	}
	res_begin = res;
	save_s2 = s2;
	while (s1 && *s1)
		*res++ = *s1++;
	while (s2 && *s2)
		*res++ = *s2++;
	*res = '\0';
	if (save_s2 != NULL)
		free((char*)save_s2);
	return (res_begin);
}
