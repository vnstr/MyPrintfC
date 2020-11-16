/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test_arg_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:31:47 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 16:22:03 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	basic_test_one_arg(void)
{
	size_t	test_count = 1;

	printf("\n~~~~~~~Spec: %%u one argument~~~~~~~~\n");
	printf("~~~~~~~~~~Basic Test Start~~~~~~~~~~\n");

	// 01
	printf("test: %zu\n", test_count++);
	printf("NEED: |%u|\n", -1789745);
	printf("YOUR: |");
	ft_printf("%u", -1789745);
	printf("|\n");

	// 02
	printf("test: %zu\n", test_count++);
	printf("NEED: |%20u|\n", -1789745);
	printf("YOUR: |");
	ft_printf("%20u", -1789745);
	printf("|\n");

	// 03
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-20u|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%-20u", 1789745);
	printf("|\n");

	// 04
	printf("test: %zu\n", test_count++);
	printf("NEED: |%020u|\n", -1789745);
	printf("YOUR: |");
	ft_printf("%020u", -1789745);
	printf("|\n");

	// 05
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*d|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*d", 15, 1789745);
	printf("|\n");

	// 06
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*u|\n", -15, 178974500);
	printf("YOUR: |");
	ft_printf("%*u", -15, 178974500);
	printf("|\n");

	// 07
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*u|\n", 15, -1789745);
	printf("YOUR: |");
	ft_printf("%-*u", 15, -1789745);
	printf("|\n");

	// 08
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*u|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%0*u", 15, 1789745);
	printf("|\n");

	// 09
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.50u|\n", 15, -1789745);
	printf("YOUR: |");
	ft_printf("%*.50u", 15, -1789745);
	printf("|\n");

	// 10
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.2u|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*.2u", 15, 1789745);
	printf("|\n");

	// 11
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*d|\n", 15, 50, 1789745);
	printf("YOUR: |");
	ft_printf("%-*.*u", 15, 50, 1789745);
	printf("|\n");

	// 12
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*u|\n", 15, 2, 1789745);
	printf("YOUR: |");
	ft_printf("%-*.*d", 15, 2, 1789745);
	printf("|\n");

	// 13
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*u|\n", 15, -50, -1789745);
	printf("YOUR: |");
	ft_printf("%-*.*u", 15, -50, -1789745);
	printf("|\n");

	// 14
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*u|\n", 15, -50, 0);
	printf("YOUR: |");
	ft_printf("%-*.*d", 15, -50, 0);
	printf("|\n");

	// 15
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*u|\n", 15, -50, -213460);
	printf("YOUR: |");
	ft_printf("%-*.*u", 15, -50, -213460);
	printf("|\n");

	// 16
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*u|\n", 15, -50, -1);
	printf("YOUR: |");
	ft_printf("%-*.*u", 15, -50, -1);
	printf("|\n");

	// 17
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*u|\n", 15, -50, 0);
	printf("YOUR: |");
	ft_printf("%-*.*u", 15, -50, 0);
	printf("|\n");


	printf("\n~~~~~~~~~~Basic Test End!~~~~~~~~~~~\n");

	return ;
}

void		basic_test_arg_u(void)
{
	basic_test_one_arg();
	return ;
}