/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:03:03 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 01:04:32 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	The function 'apply_precision_p' applies
**	flag 'precision' if needed.
*/

static int	apply_precision_p(t_spec_info *lst)
{
	char	*save;
	int		i;
	int		j;

	if (lst->flags.precision <= lst->arg_len - 2)
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
	while (i < lst->all_len)
		lst->arg[i++] = save[j++];
	lst->arg[1] = 'x';
	lst->arg_len = lst->all_len;
	return (0);
}

/*
**	The function 'apply_zero_p' applies
**	flag 'zero', if needed.
*/

static void	apply_zero_p(t_spec_info *lst)
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
**	Function returns malloc-string "(null)".
*/

char		*take_null_s(void)
{
	char	*res;

	if ((res = (char*)malloc(sizeof(char) * 7)) == NULL)
		return (NULL);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'u';
	res[3] = 'l';
	res[4] = 'l';
	res[5] = ')';
	res[6] = '\0';
	return (res);
}

/*
**	The function 'take_arg_p' puts unsigned int64 argument
**	to lst->arg with applying all needs flags and
**	converting to hex.
*/

int			take_arg_p(t_spec_info *lst, va_list factor)
{
	if ((lst->arg = ft_prf_uitoa_base(va_arg(factor, uint64_t), HEX)) == NULL)
		return (-1);
	if ((lst->arg = ft_prf_strjoin("0x", lst->arg)) == NULL)
		return (-1);
	if (lst->arg[2] == '0' && lst->flags.precision == 0)
		lst->arg[2] = '\0';
	lst->arg_len = ft_prf_strlen(lst->arg);
	lst->all_len = lst->arg_len;
	if (apply_precision_p(lst) == -1)
		return (-1);
	if (apply_width_s(lst) == -1)
		return (-1);
	if (lst->flags.minus == '-')
		apply_minus_s(lst);
	if (lst->flags.zero == '0' && lst->flags.precision < 0)
		apply_zero_p(lst);
	return (0);
}
