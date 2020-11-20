/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:42:54 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 16:26:04 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

/*
**	The function 'take_precision' puts
**	precision to lst->flags.precision
**	from string or argument.
**	If finds minus, puts minus to lst->flags.minus.
*/

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

/*
**	The function 'take_width' puts
**	width to lst->flags.width
**	from string or argument.
*/

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

/*
**	The function 'is_flag' returns
**	1 if symbol is flag. And returns 0
**	if is not.
*/

int				is_flag(char c)
{
	return (c == '-' || c == '*' || c == '.' || (c >= '0' && c <= '9'));
}

/*
**	The function 'take_flags' puts all
**	finds flags in string to lst->flags.
**	Flags: (0 - * .).
*/

void			take_flags(char *s, t_spec_info *lst, va_list factor)
{
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
