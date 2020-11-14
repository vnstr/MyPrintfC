/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:30:12 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/15 00:26:17 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

static int		apply_width_c(t_spec_info *lst)
{
	int	i;
	
	lst->all_len = lst->flags.width;
	if (lst->all_len == 0)
		lst->all_len = 1;
	if ((lst->arg = (char*)malloc(sizeof(char) * (lst->all_len + 1))) == NULL)
		return (-1);
	(lst->arg)[lst->all_len] = '\0';
	i = lst->all_len;
	while (i--)
		(lst->arg)[i] = ' ';
	return (0);
}

static void		apply_arg_c(t_spec_info *lst, va_list factor)
{
	int	i;
	if (lst->flags.minus == '-')
	{
		lst->arg[0] = va_arg(factor, int);
		return ;
	}
	else if (lst->flags.zero == '0')
	{
		i = 0;
		while (i < lst->all_len - 1)
			lst->arg[i++] = '0';
	}
	lst->arg[lst->all_len - 1] = va_arg(factor, int);
}

int				take_arg_c(t_spec_info *lst, va_list factor)
{
	lst->all_len = 1;
	lst->arg_len = 1;
	if (apply_width_c(lst) == -1)
		return (-1);
	apply_arg_c(lst, factor);
	return (0);
}
