/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:39:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 01:03:12 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*
**	The function 'take_arg_u' puts unsigned int argument
**	to lst->arg with applying all needs flags
*/

int	take_arg_u(t_spec_info *lst, va_list factor)
{
	if ((lst->arg = ft_prf_uitoa(va_arg(factor, uint32_t))) == NULL)
		return (-1);
	if (lst->arg[0] == '0' && lst->flags.precision == 0)
		lst->arg[0] = '\0';
	lst->arg_len = ft_prf_strlen(lst->arg);
	lst->all_len = lst->arg_len;
	if (apply_precision_d(lst) == -1)
		return (-1);
	if (apply_width_s(lst) == -1)
		return (-1);
	if (lst->flags.minus == '-')
		apply_minus_s(lst);
	else if (lst->flags.zero == '0' && lst->flags.precision < 0)
		apply_zero_s(lst);
	return (0);
}
