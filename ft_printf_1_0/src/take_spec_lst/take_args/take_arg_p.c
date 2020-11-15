/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:03:03 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 02:16:50 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	The function 'apply_precision_p' applies
**	flag 'precision' if needed.
*/

int static apply_precision_p(t_spec_info *lst)
{
	char	*save;
	size_t	i;
	size_t	j;

	if (lst->flags.precision <= lst->arg_len)
		return (0);
	lst->all_len = lst->flags.precision + 2;
	save = lst->arg;
	if ((lst->arg = (char*)malloc(sizeof(char) * (lst->all_len + 1))) == NULL)
	{
		free(save);
		return (-1);
	}
	lst->arg[lst->all_len] = '\0';
	i = 0;
	while (i < lst->all_len - lst->arg_len + 2)
		lst->arg[i++] = '0';
	j = 2;
	while(i < lst->all_len)
		lst->arg[i++] = save[j++];
	lst->arg[1] = 'x';
	lst->arg_len = lst->all_len;
	return (0);
}

/*
**	The function 'apply_zero_p' applies
**	flag 'zero' if needed.
*/

void static	apply_zero_p(t_spec_info *lst)
{
	int	i;

	if (lst->all_len <= lst->arg_len)
		return ;
	i = 0;
	while (lst->arg[i] != 'x')
		lst->arg[i++] = '0';
	lst->arg[i] = '0';
	lst->arg[1] = 'x';
}

/*
**	The function 'take_arg_p' puts
**	pointer argument to lst->arg with
**  applying all needs flags.
*/

int	take_arg_p(t_spec_info *lst, va_list factor)
{
	if ((lst->arg = ft_prf_uitoa_base(va_arg(factor, uint64_t), HEX)) == NULL)
		return (-1);
	if ((lst->arg = ft_prf_strjoin("0x", lst->arg)) == NULL)
		return (-1);
	lst->arg_len = ft_prf_strlen(lst->arg);
	lst->all_len = lst->arg_len;
	if (apply_precision_p(lst) == -1)
		return (-1);
	if (apply_width_s(lst) == -1)
		return (-1);
	if (lst->flags.minus == '-')
		apply_minus_s(lst);
	else if (lst->flags.zero == '0')
		apply_zero_p(lst);
	return (0);
}