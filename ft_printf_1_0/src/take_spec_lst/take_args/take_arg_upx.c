/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_upx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:07:57 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 20:13:32 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	take_arg_upx(t_spec_info *lst, va_list factor)
{
	if ((lst->arg = ft_prf_uitoa_base(va_arg(factor, uint32_t), UHEX)) == NULL)
		return (-1);
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