/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test_arg_upx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:10:34 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 20:17:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	basic_test_one_arg(void)
{
	size_t	test_count = 1;

	printf("\n~~~~~~~Spec: %%X one argument~~~~~~~~\n");
	printf("~~~~~~~~~~Basic Test Start~~~~~~~~~~\n");

	// 01
	printf("test: %zu\n", test_count++);
	printf("NEED: |%X|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%X", 1789745);
	printf("|\n");

	// 02
	printf("test: %zu\n", test_count++);
	printf("NEED: |%20X|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%20X", 1789745);
	printf("|\n");

	// 03
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-20X|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%-20X", 1789745);
	printf("|\n");

	// 04
	printf("test: %zu\n", test_count++);
	printf("NEED: |%020X|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%020X", 1789745);
	printf("|\n");

	// 05
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*X|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*X", 15, 1789745);
	printf("|\n");

	// 06
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*X|\n", -15, 1789745);
	printf("YOUR: |");
	ft_printf("%*X", -15, 1789745);
	printf("|\n");

	// 07
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*X|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%-*X", 15, 1789745);
	printf("|\n");

	// 08
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*X|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%0*X", 15, 1789745);
	printf("|\n");

	// 09
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.50X|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*.50X", 15, 1789745);
	printf("|\n");

	// 10
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.2X|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*.2X", 15, 1789745);
	printf("|\n");

	// 11
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*X|\n", 15, 50, -1789745);
	printf("YOUR: |");
	ft_printf("%-*.*X", 15, 50, -1789745);
	printf("|\n");

	// 12
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*X|\n", 15, 2, 1789745);
	printf("YOUR: |");
	ft_printf("%-*.*X", 15, 2, 1789745);
	printf("|\n");

	// 13
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*X|\n", 15, -50, -1789745);
	printf("YOUR: |");
	ft_printf("%-*.*X", 15, -50, -1789745);
	printf("|\n");

	// 14
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*X|\n", 15, -50, 0);
	printf("YOUR: |");
	ft_printf("%-*.*X", 15, -50, 0);
	printf("|\n");

	// 15
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*X|\n", 15, -50, -213460);
	printf("YOUR: |");
	ft_printf("%-*.*X", 15, -50, -213460);
	printf("|\n");

	// 16
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*.*X|\n", 50, 10, -10);
	printf("YOUR: |");
	ft_printf("%0*.*X", 50, 10, -10);
	printf("|\n");


	printf("\n~~~~~~~~~~Basic Test End!~~~~~~~~~~~\n");

	return ;
}

void		basic_test_arg_upx(void)
{
	basic_test_one_arg();
	return ;
}