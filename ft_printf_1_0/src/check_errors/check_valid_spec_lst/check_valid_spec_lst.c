/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_spec_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:01:19 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/14 16:23:05 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			is_spec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int			check_valid_spec_lst(t_spec_info *begin_lst)
{
	t_spec_info	*tmp;

	if ((tmp = begin_lst) == NULL)
		return (-1);
	while (tmp != NULL)
	{
		if ((is_spec(tmp->spec)) == 0)
			return (-1);
		tmp = tmp->next;
	}
	write(1, "check valid spec end!\n", 22);
	return (0);
}