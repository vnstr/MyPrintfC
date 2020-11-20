/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:17:28 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/21 01:01:59 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

/*
**	The function 'apply_precision_s' applies
**	flag 'precision' if needed.
*/

static int	apply_precision_s(t_spec_info *lst)
{
	int		i;
	char	*save;

	if (lst->flags.precision < 0 || lst->flags.precision > lst->arg_len)
		return (0);
	save = lst->arg;
	lst->arg_len = lst->flags.precision;
	if ((lst->arg = (char*)malloc(sizeof(char) * (lst->arg_len + 1))) == NULL)
		return (-1);
	i = lst->arg_len;
	lst->arg[i] = '\0';
	while (i--)
		lst->arg[i] = save[i];
	lst->all_len = lst->arg_len;
	return (0);
}

/*
**	The function 'apply_width_s' applies
**	flag 'width' if needed.
*/

int			apply_width_s(t_spec_info *lst)
{
	char	*save;
	int		i;
	int		j;

	if (lst->flags.width <= lst->arg_len)
		return (0);
	save = lst->arg;
	lst->all_len = lst->flags.width;
	if ((lst->arg = (char*)malloc(sizeof(char) * (lst->all_len + 1))) == NULL)
	{
		free(save);
		return (-1);
	}
	lst->arg[lst->all_len] = '\0';
	i = lst->all_len;
	j = lst->arg_len;
	while (j >= 0)
		lst->arg[i--] = save[j--];
	while (i >= 0)
		lst->arg[i--] = ' ';
	free(save);
	return (0);
}

/*
**	The function 'apply_minus_s' applies
**	flag 'minus' if needed.
*/

void		apply_minus_s(t_spec_info *lst)
{
	int	i;
	int	j;

	if (lst->all_len <= lst->arg_len)
		return ;
	i = 0;
	j = lst->all_len - lst->arg_len;
	while (lst->arg[j] != '\0')
		lst->arg[i++] = lst->arg[j++];
	while (lst->arg[i] != '\0')
		lst->arg[i++] = ' ';
	return ;
}

/*
**	The function 'apply_zero_s' applies
**	flag 'zero' if needed.
*/

void		apply_zero_s(t_spec_info *lst)
{
	int	i;

	if (lst->all_len <= lst->arg_len)
		return ;
	i = 0;
	while (i < (lst->all_len - lst->arg_len))
		lst->arg[i++] = '0';
	return ;
}

/*
**	The function 'take_arg_s' puts char* argument
**	to lst->arg with applying all needs flags.
*/

int			take_arg_s(t_spec_info *lst, va_list factor)
{
	if ((lst->arg = va_arg(factor, char*)) == NULL)
	{
		if ((lst->arg = take_null_s()) == NULL)
			return (-1);
	}
	else
	{
		if ((lst->arg = ft_prf_strjoin(lst->arg, NULL)) == NULL)
			return (-1);
	}
	lst->arg_len = (int)ft_prf_strlen(lst->arg);
	lst->all_len = lst->arg_len;
	if (apply_precision_s(lst) == -1)
		return (-1);
	if (apply_width_s(lst) == -1)
		return (-1);
	if (lst->flags.minus == '-')
		apply_minus_s(lst);
	else if (lst->flags.zero == '0')
		apply_zero_s(lst);
	return (0);
}
