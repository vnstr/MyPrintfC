/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_result_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:42:22 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/17 20:49:28 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Counting all characters in str for printing.
*/

static size_t	take_useful_len(const char *s)
{
	size_t	useful_len;

	useful_len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			while (*s != '\0' && is_flag(*s))
				s++;
			if (*s != '\0')
				s++;
			continue ;
		}
		s++;
		useful_len++;
	}
	return (useful_len);
}

/*
**	Sums all (lst->all_len), and return it.
*/

static size_t	take_spec_all_lens(t_spec_info *spec_lst)
{
	size_t	all_lens;

	all_lens = 0;
	while (spec_lst != NULL)
	{
		all_lens += spec_lst->all_len;
		spec_lst = spec_lst->next;
	}
	return (all_lens);
}

/*
**	Copying from (arg) to (s) with the given start's (s).
*/

static size_t	take_arg(char *s, t_spec_info *lst, size_t start)
{
	int	j;

	j = 0;
	while (j < lst->all_len)
		s[start++] = lst->arg[j++];
	return (start);
}

/*
**	Allocating and writing str for printing.
*/

int				take_res_s(const char *s, t_result_str *res_s, t_spec_info *lst)
{
	t_spec_info		*tmp;
	size_t			i;

	res_s->str_len = take_spec_all_lens(lst) + take_useful_len(s);
	if ((res_s->str = (char*)malloc((res_s->str_len + 1))) == NULL)
		return (-1);
	res_s->str[res_s->str_len] = '\0';
	i = 0;
	tmp = lst;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			i = take_arg(res_s->str, tmp, i);
			tmp = tmp->next;
			s++;
			while (*s != '\0' && is_flag(*s))
				s++;
			if (*s != '\0')
				s++;
			continue ;
		}
		res_s->str[i++] = *s++;
	}
	return (0);
}
