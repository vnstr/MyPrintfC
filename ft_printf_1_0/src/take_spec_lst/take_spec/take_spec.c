/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:06:22 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/17 17:01:58 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"


char	*take_spec(char *s, t_spec_info *lst)
{
	if (*s != '\0' && *s == '%')
		s++;
	while (*s != '\0' && is_flag(*s))
		s++;
	lst->spec = (*s);
	if (*s != '\0')
		return (++s);
	else
		return (s);
}
