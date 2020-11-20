/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:55:07 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 01:05:49 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			is_spec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

static int	take_args_nb(t_spec_info *lst, va_list factor)
{
	if (lst->spec == 'd' || lst->spec == 'i')
	{
		if ((take_arg_d(lst, factor)) == -1)
			return (-1);
	}
	if (lst->spec == 'u')
	{
		if ((take_arg_u(lst, factor)) == -1)
			return (-1);
	}
	return (0);
}

static int	take_args_hex(t_spec_info *lst, va_list factor)
{
	if (lst->spec == 'p')
	{
		if ((take_arg_p(lst, factor)) == -1)
			return (-1);
	}
	if (lst->spec == 'x')
	{
		if ((take_arg_x(lst, factor)) == -1)
			return (-1);
	}
	if (lst->spec == 'X')
	{
		if ((take_arg_upx(lst, factor)) == -1)
			return (-1);
	}
	return (0);
}

static int	take_args_symbols(t_spec_info *lst, va_list factor)
{
	if (lst->spec == 'c')
	{
		if ((take_arg_c(lst, factor, '\0')) == -1)
			return (-1);
	}
	if (lst->spec == 's')
	{
		if ((take_arg_s(lst, factor)) == -1)
			return (-1);
	}
	if (is_spec(lst->spec) == 0)
	{
		if ((take_arg_c(lst, factor, lst->spec)) == -1)
			return (-1);
	}
	return (0);
}

/*
**	Puts all arguments to lst->arg
**	with applying all needs flags.
*/

int			take_args(t_spec_info *lst, va_list factor)
{
	if (take_args_nb(lst, factor) == -1)
		return (-1);
	if (take_args_hex(lst, factor) == -1)
		return (-1);
	if (take_args_symbols(lst, factor) == -1)
		return (-1);
	return (0);
}
