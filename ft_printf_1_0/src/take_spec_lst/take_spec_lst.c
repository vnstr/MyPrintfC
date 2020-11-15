/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_spec_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:06:08 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/15 14:54:49 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Требуется реализовать:
 *
 * Спецификаторы:
 * %c символ char
 * %s строка
 * %p значение указателя
 * %d десятичное число целого типа со знаком
 * %i десятичное число целого типа со знаком
 * %u десятичное число целого типа без знака
 * %x Шестнадцатиричное целое число без знака (буквы нижнего регистра)
 * %X Шестнадцатиричное целое число без знака (буквы верхнего регистра)
 * --------------------------------------------------------------------
 *
 * Флаги:
 * - (дефис) результат преобразования выравнивается по левому краю
 *   (по умолчанию - по правому краю)
 *
 * 0 если не указан флаг '-', то слева от выводимого числа будут
 *   выведены символы '0' для подгона числа к указанной ширене.
 *   Если для преобразователей d, i, o, x или X указана точность,
 *   то флаг 0 игнорируется.
 *
 * * Спецификатор [ширина] задаёт минимальный размер выводимого числа в символах.
 *   Если количество символов в выводимом числе меньше указанной минимальной ширины,
 *   то недостоющее количество символов заполняется нулями
 *   или пробелами слева или справа в зависимости от указанных флагов.
 *   Ширина указывается либо целым числом, либо символом *
 *   с последующим указанием имени переменной типа int, содержащей значение ширины,
 *   перед аргументом к которому он относится. Если аргумент имеет отрицательное значение,
 *   то он эквивалентен соответствующему положительному значению с флагом "-".
 *
 * . Действия спецификатора [точность] зависит от типа выводимого числа:
 *   - Для типов d, i, o, u, x, X определяет минимальное число выводимых цифр.
 *     Если количество выводимых цифр в числе меньше,
 *     чем указано в спецификаторе [точность], то выводимое число
 *     будет дополнено нулями слева. Например, если при выводе числа 126 указать точность 4,
 *     то на экран будет выведено число 0126
 *
 *   - Точность указывается в виде символа точка, за которым следует десятичное число
 *     или символ "*", с последующим указанием имени переменной типа int, содержащей
 *     значение точности, перед аргументом к которому он относится.
 *
 *   - Спецификатор [точность] можно не указывать.
 */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

t_spec_info	*take_spec_lst(const char *s, va_list factor)
{
	t_spec_info	*begin_lst;
	t_spec_info	*current_lst;

	
	begin_lst = NULL;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			if ((current_lst = spec_lst_add_back(&begin_lst, (char*)s)) == NULL)
				return (spec_lst_clear(&begin_lst));
			take_flags((char*)s, current_lst, factor);
			s =take_spec((char*)s, current_lst);
			if ((take_args(current_lst, factor)) == -1)
				return (spec_lst_clear(&begin_lst));
			continue ;
		}
		s++;
	}
	// if ((check_valid_spec_lst(begin_lst)) == -1)
	// 			return (spec_lst_clear(&begin_lst));
	print_spec_lst(begin_lst);
	// print_arg_lst(begin_lst);
	return (NULL);
}
