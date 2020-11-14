/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:55:07 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/14 16:27:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			take_args(t_spec_info *begin_lst, va_list factor)
{
	t_spec_info	*tmp;

	tmp = begin_lst;
	while (tmp != NULL)
	{
		if (tmp->spec == 'c')
		{
			if ((take_arg_c(tmp, factor)) == -1)
				return (-1);
		}
		if (tmp->spec == 's')
		{
			if ((take_arg_s(tmp, factor)) == -1)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}
