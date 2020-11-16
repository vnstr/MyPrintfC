/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test_arg_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:12:18 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 17:53:27 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	basic_test_one_arg(void)
{
	size_t	test_count = 1;

	printf("\n~~~~~~~Spec: %%d one argument~~~~~~~~\n");
	printf("~~~~~~~~~~Basic Test Start~~~~~~~~~~\n");

	// 01
	printf("test: %zu\n", test_count++);
	printf("NEED: |%d|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%d", 1789745);
	printf("|\n");

	// 02
	printf("test: %zu\n", test_count++);
	printf("NEED: |%20d|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%20d", 1789745);
	printf("|\n");

	// 03
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-20d|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%-20d", 1789745);
	printf("|\n");

	// 04
	printf("test: %zu\n", test_count++);
	printf("NEED: |%020d|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%020d", 1789745);
	printf("|\n");

	// 05
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*d|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*d", 15, 1789745);
	printf("|\n");

	// 06
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*d|\n", -15, 1789745);
	printf("YOUR: |");
	ft_printf("%*d", -15, 1789745);
	printf("|\n");

	// 07
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*d|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%-*d", 15, 1789745);
	printf("|\n");

	// 08
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*d|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%0*d", 15, 1789745);
	printf("|\n");

	// 09
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.50d|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*.50d", 15, 1789745);
	printf("|\n");

	// 10
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.2d|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*.2d", 15, 1789745);
	printf("|\n");

	// 11
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*d|\n", 15, 50, -1789745);
	printf("YOUR: |");
	ft_printf("%-*.*d", 15, 50, -1789745);
	printf("|\n");

	// 12
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*d|\n", 15, 2, 1789745);
	printf("YOUR: |");
	ft_printf("%-*.*d", 15, 2, 1789745);
	printf("|\n");

	// 13
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*d|\n", 15, -50, -1789745);
	printf("YOUR: |");
	ft_printf("%-*.*d", 15, -50, -1789745);
	printf("|\n");

	// 14
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*d|\n", 15, -50, 0);
	printf("YOUR: |");
	ft_printf("%-*.*d", 15, -50, 0);
	printf("|\n");

	// 15
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*d|\n", 15, -50, -213460);
	printf("YOUR: |");
	ft_printf("%-*.*d", 15, -50, -213460);
	printf("|\n");

	// 16
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*.*d|\n", 50, 10, -10);
	printf("YOUR: |");
	ft_printf("%0*.*d", 50, 10, -10);
	printf("|\n");


	printf("\n~~~~~~~~~~Basic Test End!~~~~~~~~~~~\n");

	return ;
}

void		basic_test_arg_d(void)
{
	basic_test_one_arg();
	return ;
}