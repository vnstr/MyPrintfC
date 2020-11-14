/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arg_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 23:22:37 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/15 01:04:35 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	print_arg_lst(t_spec_info *begin_lst)
{
	while (begin_lst)
	{
		printf("%s", begin_lst->arg);
		begin_lst = begin_lst->next;
	}
	return ;
}