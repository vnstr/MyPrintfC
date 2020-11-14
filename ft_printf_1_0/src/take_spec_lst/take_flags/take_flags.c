/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:42:54 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/14 19:16:24 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static char		*take_precision(char *s, t_spec_info *lst, va_list factor)
{
	if (*s == '-')
	{
		lst->flags.precision = 0;
		lst->flags.minus = '-';
		return (++s);
	}
	if (*s == '*')
	{
		lst->flags.precision = va_arg(factor, int);
		return (++s);
	}
	lst->flags.precision = ft_prf_atoi(s);
	while (*s != '\0' && *s >= '0' && *s <= '9')
		s++;
	return (s);
}

static char		*take_width(char *s, t_spec_info *lst, va_list factor)
{
	if (*s == '*')
	{
		lst->flags.width = va_arg(factor, int);
		if (lst->flags.width < 0)
			{
				lst->flags.minus = '-';
				lst->flags.width *= -1;
			}
		return (++s);
	}
	lst->flags.width = ft_prf_atoi(s);
	while (*s != '\0' && *s >= '0' && *s <= '9')
		s++;
	return (s);
}

int				is_flag(char c)
{
	return (c == '-' || c == '*' || c == '.' || (c >= '0' && c <= '9'));
}

void			take_flags(char *s, t_spec_info *lst, va_list factor)
{
	if (*s == '%')
		s++;
	while (is_flag(*s))
	{
		if (*s == '-')
			lst->flags.minus = '-';
		if (*s == '0')
			lst->flags.zero = '0';
		if (*s == '*' || (*s >= '1' && *s <= '9'))
		{
			s = take_width(s, lst, factor);
			continue ;
		}
		if (*s == '.')
		{
			s = take_precision(s + 1, lst, factor);
			continue ;
		}
		s++;
	}
}
