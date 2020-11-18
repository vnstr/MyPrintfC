/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_lst_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:21:37 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/17 16:32:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

/*
**	Function creates element of list, wich is described in "ft_printf.h",
**	and setup 0, '\0' or NULL for all properties.
*/

void		zero_flags_info(t_spec_info *lst)
{
	lst->flags.minus = '\0';
	lst->flags.zero = '\0';
	lst->flags.width = 0;
	lst->flags.precision = -1;
	return ;
}

t_spec_info	*spec_lst_create(void)
{
	t_spec_info	*new_lst;

	if ((new_lst = (t_spec_info*)malloc(sizeof(t_spec_info))) == NULL)
		return (NULL);
	new_lst->spec = '\0';
	new_lst->spec_ptr = NULL;
	zero_flags_info(new_lst);
	new_lst->arg = NULL;
	new_lst->arg_len = 0;
	new_lst->all_len = 0;
	new_lst->next = NULL;
	return (new_lst);
}
