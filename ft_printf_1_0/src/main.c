/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:36:33 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 02:28:49 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*ptr = "abc";

	basic_test_arg_c();
	basic_test_arg_s();
	basic_test_arg_p();
	// ft_printf("%*.50p", 15, 1789745);
	// ft_printf("%c", 'A');
	return (0);
}
