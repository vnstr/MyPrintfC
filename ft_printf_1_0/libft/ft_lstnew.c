/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:46:53 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/03 14:05:02 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p_elem;

	if (!(p_elem = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (p_elem)
	{
		p_elem->next = 0;
		p_elem->content = content;
	}
	return (p_elem);
}
