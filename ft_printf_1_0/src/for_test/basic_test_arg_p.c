/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test_arg_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 01:23:49 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/16 02:28:43 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	basic_test_one_arg(void)
{
	size_t	test_count = 1;

	printf("\n~~~~~~~Spec: %%p one argument~~~~~~~~\n");
	printf("~~~~~~~~~~Basic Test Start~~~~~~~~~~\n");

	// 01
	printf("test: %zu\n", test_count++);
	printf("NEED: |%p|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%p", 1789745);
	printf("|\n");

	// 02
	printf("test: %zu\n", test_count++);
	printf("NEED: |%20p|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%20p", 1789745);
	printf("|\n");

	// 03
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-20p|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%-20p", 1789745);
	printf("|\n");

	// 04
	printf("test: %zu\n", test_count++);
	printf("NEED: |%020p|\n", 1789745);
	printf("YOUR: |");
	ft_printf("%020p", 1789745);
	printf("|\n");

	// 05
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*p|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*p", 15, 1789745);
	printf("|\n");

	// 06
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*p|\n", -15, 1789745);
	printf("YOUR: |");
	ft_printf("%*p", -15, 1789745);
	printf("|\n");

	// 07
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*p|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%-*p", 15, 1789745);
	printf("|\n");

	// 08
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*p|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%0*p", 15, 1789745);
	printf("|\n");

	// 09
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.50p|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*.50p", 15, 1789745);
	printf("|\n");

	// 10
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.2p|\n", 15, 1789745);
	printf("YOUR: |");
	ft_printf("%*.2p", 15, 1789745);
	printf("|\n");

	// 11
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*p|\n", 15, 50, 1789745);
	printf("YOUR: |");
	ft_printf("%-*.*p", 15, 50, 1789745);
	printf("|\n");

	// 12
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*p|\n", 15, 2, 1789745);
	printf("YOUR: |");
	ft_printf("%-*.*p", 15, 2, 1789745);
	printf("|\n");

	// 13
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*p|\n", 15, -50, 1789745);
	printf("YOUR: |");
	ft_printf("%-*.*p", 15, -50, 1789745);
	printf("|\n");

	// 14
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*p|\n", 15, -50, 0);
	printf("YOUR: |");
	ft_printf("%-*.*p", 15, -50, 0);
	printf("|\n");

	// 15
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*p|\n", 15, -50, -213467);
	printf("YOUR: |");
	ft_printf("%-*.*p", 15, -50, -213467);
	printf("|\n");

	// 16
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*p|\n", 15, -50, 1);
	printf("YOUR: |");
	ft_printf("%-*.*p", 15, -50, 1);
	printf("|\n");


	printf("\n~~~~~~~~~~Basic Test End!~~~~~~~~~~~\n");

	return ;
}

void		basic_test_arg_p(void)
{
	basic_test_one_arg();
	return ;
}