/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_spec_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:06:08 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 01:08:28 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

/*
**	Function parses string. Looking for flags and types after '%' in string.
**	Then applys it for argument.
**	The received data is saved in the list,
**	wich is described in the "ft_printf.h".
*/

t_spec_info	*take_spec_lst(const char *s, va_list factor)
{
	t_spec_info	*begin_lst;
	t_spec_info	*current_lst;

	begin_lst = NULL;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			if ((current_lst = spec_lst_add_back(&begin_lst, (char*)s)) == NULL)
				return (spec_lst_clear(&begin_lst));
			take_flags((char*)(s + 1), current_lst, factor);
			s = take_spec((char*)(s + 1), current_lst);
			if ((take_args(current_lst, factor)) == -1)
				return (spec_lst_clear(&begin_lst));
			continue ;
		}
		s++;
	}
	return (begin_lst);
}
