/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:36:33 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 20:11:40 by gdrive           ###   ########.fr       */
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
	basic_test_arg_d();
	basic_test_arg_u();
	basic_test_arg_x();
	basic_test_arg_upx();

	return (0);
}
