/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:21:01 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 00:59:07 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*
**	The function 'apply_precision_minus_d' applies
**	flag 'precision' for numberbs < 0, if needed.
*/

int		apply_precision_minus_d(t_spec_info *lst)
{
	char	*save;
	int		i;
	int		j;

	if (lst->flags.precision < lst->arg_len)
		return (0);
	lst->arg_len--;
	save = lst->arg;
	lst->all_len = lst->flags.precision + 1;
	if ((lst->arg = (char*)malloc(sizeof(char) * (lst->all_len + 1))) == NULL)
	{
		free(save);
		return (-1);
	}
	lst->arg[lst->all_len] = '\0';
	lst->arg[0] = '-';
	i = 1;
	while (i < lst->all_len - lst->arg_len)
		lst->arg[i++] = '0';
	j = 1;
	while (i < lst->all_len)
		lst->arg[i++] = save[j++];
	lst->arg_len = ft_prf_strlen(lst->arg);
	lst->all_len = lst->arg_len;
	return (0);
}

/*
**	The function 'apply_precision_minus_d' applies
**	flag 'precision' for numberbs >= 0, if needed.
*/

int		apply_precision_d(t_spec_info *lst)
{
	char	*save;
	int		i;
	int		j;

	if (lst->arg[0] == '-')
		return (apply_precision_minus_d(lst));
	if (lst->flags.precision <= lst->arg_len)
		return (0);
	save = lst->arg;
	lst->all_len = lst->flags.precision;
	if ((lst->arg = (char*)malloc(sizeof(char) * (lst->all_len + 1))) == NULL)
	{
		free(save);
		return (-1);
	}
	lst->arg[lst->all_len] = '\0';
	i = 0;
	while (i < lst->all_len - lst->arg_len)
		lst->arg[i++] = '0';
	j = 0;
	while (i < lst->all_len)
		lst->arg[i++] = save[j++];
	lst->arg_len = lst->all_len;
	return (0);
}

/*
**	The function 'apply_zero_d' applies
**	flag 'zero', if needed.
*/

void	apply_zero_d(t_spec_info *lst)
{
	int	i;
	int	sign;

	if (lst->all_len <= lst->arg_len)
		return ;
	sign = 1;
	if (lst->arg[lst->all_len - lst->arg_len] == '-')
		sign = -1;
	if (sign > 0)
	{
		i = 0;
		while (i < (lst->all_len - lst->arg_len))
			lst->arg[i++] = '0';
		return ;
	}
	i = 1;
	while (i < (lst->all_len - lst->arg_len + 1))
		lst->arg[i++] = '0';
	lst->arg[0] = '-';
	return ;
}
 
/*
**	The function 'take_arg_d' puts int argument
**	to lst->arg with applying all needs flags
*/

int		take_arg_d(t_spec_info *lst, va_list factor)
{
	if ((lst->arg = ft_prf_itoa(va_arg(factor, int))) == NULL)
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
		apply_zero_d(lst);
	return (0);
}
