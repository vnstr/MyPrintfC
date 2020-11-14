/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:55:07 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/15 00:29:31 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			take_args(t_spec_info *lst, va_list factor)
{
	if (lst->spec == 'c')
	{
		if ((take_arg_c(lst, factor)) == -1)
			return (-1);
	}
	if (lst->spec == 's')
	{
		if ((take_arg_s(lst, factor)) == -1)
			return (-1);
	}
	return (0);
}
