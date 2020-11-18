/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:30:12 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/17 21:03:11 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

/*
**	The function 'apply_width_c' applies
**	flag 'width' if needed. Else creates
**	2 bytes string with ' ' and '\0'.
*/

static int		apply_width_c(t_spec_info *lst)
{
	int	i;

	if (lst->arg_len < lst->flags.width)
		lst->all_len = lst->flags.width;
	if ((lst->arg = (char*)malloc(sizeof(char) * (lst->all_len + 1))) == NULL)
		return (-1);
	(lst->arg)[lst->all_len] = '\0';
	i = lst->all_len;
	while (i-- != 0)
		(lst->arg)[i] = ' ';
	if (lst->arg_len == 0)
		lst->all_len = 1;
	return (0);
}

/*
**	The function 'apply_arg_c' puts
**	char argument to lst->arg with applying
**	flag 'minus' or flag '0', after
**	apllying flag width.
*/

static void		apply_arg_c(t_spec_info *lst, va_list factor, char c)
{
	int	i;

	if (lst->arg_len > 0 && lst->flags.minus == '-')
	{
		if (is_spec(lst->spec) == 1)
		{
			lst->arg[0] = va_arg(factor, int);
		}
		else
			lst->arg[0] = c;
		return ;
	}
	else if (lst->arg_len > 0 && lst->flags.zero == '0')
	{
		i = 0;
		while (i < lst->all_len - 1)
			lst->arg[i++] = '0';
	}
	if (lst->arg_len > 0 && is_spec(lst->spec) == 1)
		lst->arg[lst->all_len - 1] = va_arg(factor, int);
	else if (lst->arg_len > 0)
		lst->arg[lst->all_len - 1] = c;
}

/*
**	The function 'take_arg_c' puts
**	char argument to lst->arg with
**  applying all needs flags.
*/

int				take_arg_c(t_spec_info *lst, va_list factor, char c)
{
	if (lst->spec == '\0' && c == '\0')
		lst->arg_len = 0;
	else
		lst->arg_len = 1;
	lst->all_len = lst->arg_len;
	if (apply_width_c(lst) == -1)
		return (-1);
	apply_arg_c(lst, factor, c);
	return (0);
}
