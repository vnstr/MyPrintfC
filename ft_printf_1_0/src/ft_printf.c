/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:35:56 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/11 17:40:52 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *s, ...)
{
	t_spec_info	*spec_lst;
	va_list		arg_p;
	// Парсинг строки

	va_start(arg_p, s);
	spec_lst = take_spec_lst(s, arg_p);
	va_end(arg_p);

	///////////////////////////////////

	//Работа с аргументами
	/*
	va_list	arg_p;
	va_arg(arg_p,double);
	va_start(arg_p, s);
	*/////////////////////

	return (0);
}
