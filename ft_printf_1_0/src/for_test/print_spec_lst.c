/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:35:50 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/14 18:07:53 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	print_spec_lst(t_spec_info *begin_lst)
{
	size_t		lst_count;

	lst_count = 1;
	if (begin_lst == NULL)
	{
		printf("\n~~~~~~~~~~~~~SPEC_LST - NULL~~~~~~~\n");
		return ;
	}
	printf("\n~~~~~~~~~~~~~SPEC_LST~~~~~~~~~~~~~~\n");
	while (begin_lst)
	{
		printf("\n***          LST: %zu            ***:\n\n", lst_count);
		printf("spec: \"%c\"\n", begin_lst->spec);
		printf("spec_ptr: \"%s\"\n", begin_lst->spec_ptr);

		printf("....FLAGS.....\n");
		printf("minus: %c\n", (begin_lst->flags.minus));
		printf("zero: %c\n", (begin_lst->flags.zero));
		printf("width: %d\n", (begin_lst->flags.width));
		printf("precision: %d\n", (begin_lst->flags.precision));
		printf("..............\n");

		printf("arg: \"%s\"\n", begin_lst->arg);
		printf("arg_len: %d\n", begin_lst->arg_len);
		printf("all_len: %d\n", begin_lst->all_len);
		printf("-----------------------------------\n");
		begin_lst = (*begin_lst).next;
		lst_count++;
	}
	printf("\n~~~~~~~~~~~~~~~END~~~~~~~~~~~~~~~~~\n");
	return ;
}
