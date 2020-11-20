/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:35:56 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 01:12:14 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function works like printf (man printf).
**	Realise types: %c, %s, %p, %d, %i, %u, %x, %X.
**	Realise flags: 0 - * .
*/

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int					ft_printf(const char *s, ...)
{
	t_result_str	res_s;
	t_spec_info		*spec_lst;
	va_list			arg_p;

	va_start(arg_p, s);
	spec_lst = take_spec_lst(s, arg_p);
	va_end(arg_p);
	if ((take_res_s(s, &res_s, spec_lst)) == -1)
	{
		spec_lst_clear(&spec_lst);
		return (-1);
	}
	write(1, res_s.str, res_s.str_len);
	spec_lst_clear(&spec_lst);
	free(res_s.str);
	return (res_s.str_len);
}
