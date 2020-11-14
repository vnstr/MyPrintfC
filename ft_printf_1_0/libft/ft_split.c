/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:34:02 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/05 11:21:28 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_split_free(char **strs)
{
	char	**save_start;

	save_start = strs;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
	free(save_start);
	return (0);
}

static size_t	ft_split_words_count(char *s, char c)
{
	char	new_word_flag;
	size_t	words_count;

	if (!s)
		return (0);
	new_word_flag = 1;
	words_count = 0;
	while (*s)
	{
		if (*s == c)
			new_word_flag = 1;
		if (new_word_flag && *s != c)
		{
			new_word_flag = 0;
			words_count++;
		}
		s++;
	}
	return (words_count);
}

static size_t	ft_split_word_len(char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	char	**res_begin;
	size_t	res_len;
	size_t	i;
	size_t	len_save;

	res_len = ft_split_words_count((char*)s, c);
	len_save = res_len;
	if (!(res = (char**)malloc(sizeof(char*) * (res_len + 1))))
		return (0);
	res_begin = res;
	res[res_len] = 0;
	while (res_len--)
	{
		while (*s == c && *s)
			s++;
		if (!(*res = (char*)malloc((ft_split_word_len((char*)s, c) + 1))))
			return (ft_split_free(res_begin));
		i = 0;
		while (*s != c && *s)
			(*res)[i++] = *s++;
		(*res)[i] = '\0';
		res++;
	}
	return (res_begin);
}
