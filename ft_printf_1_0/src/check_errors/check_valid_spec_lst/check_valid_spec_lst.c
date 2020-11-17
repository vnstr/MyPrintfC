/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_spec_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:01:19 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/17 12:30:40 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (0);
}