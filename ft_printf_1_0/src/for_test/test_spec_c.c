/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_spec_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 22:52:04 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/14 23:49:06 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

static void		basic_test_two_arg(void)
{
	size_t	test_count = 1;

	printf("\n~~~~~~~~~~Basic Test Start~~~~~~~~~~\n");

	// 01
	printf("test: %zu\n", test_count++);
	printf("NEED: |%c%c|\n", 'Z', 'A');
	printf("YOUR: |");
	ft_printf("%c%c", 'Z', 'A');
	printf("|\n");

	// 02
	printf("test: %zu\n", test_count++);
	printf("NEED: |%10c%5c|\n", 'Z', 'A');
	printf("YOUR: |");
	ft_printf("%10c%5c", 'Z', 'A');
	printf("|\n");

	// 03
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-10c%-5c|\n", 'Z', 'A');
	printf("YOUR: |");
	ft_printf("%-10c%-5c", 'Z', 'A');
	printf("|\n");

	// 04
	printf("test: %zu\n", test_count++);
	printf("NEED: |%010c%05c|\n", 'Z', 'A');
	printf("YOUR: |");
	ft_printf("%010c%05c", 'Z', 'A');
	printf("|\n");

	// 05
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*c%*c|\n", 10, 'Z', 5, 'A');
	printf("YOUR: |");
	ft_printf("%*c%*c", 10, 'Z', 5, 'A');
	printf("|\n");

	// 06
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*c%*c|\n", -10, 'Z', -5, 'A');
	printf("YOUR: |");
	ft_printf("%*c%*c", -10, 'Z', -5, 'A');
	printf("|\n");

	// 07
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*c%-*c|\n", 20, 'Z', 10, 'A');
	printf("YOUR: |");
	ft_printf("%-*c%-*c", 20, 'Z', 10, 'A');
	printf("|\n");

	// 08
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*c%0*c|\n", 20, 'Z', 10, 'A');
	printf("YOUR: |");
	ft_printf("%0*c%0*c", 20, 'Z', 10, 'A');
	printf("|\n");

	// 09
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.50c%*.25c|\n", 20, 'Z', 10, 'A');
	printf("YOUR: |");
	ft_printf("%*.50c%*.50c", 20, 'Z', 10, 'A');
	printf("|\n");

	// 10
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.5c%*.2c|\n", 20, 'Z', 10, 'A');
	printf("YOUR: |");
	ft_printf("%*.5c%*.2c", 20, 'Z', 10, 'A');
	printf("|\n");

	// 11
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*c%-*.*c|\n", 20, 50, 'Z', 10, 25, 'A');
	printf("YOUR: |");
	ft_printf("%-*.*c%-*.*c", 20, 50, 'Z', 10, 25, 'A');
	printf("|\n");

	// 12
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*c%-*.*c|\n", 20, 5, 'Z', 10, 2, 'A');
	printf("YOUR: |");
	ft_printf("%-*.*c%-*.*c", 20, 5, 'Z', 10, 2, 'A');
	printf("|\n");

	// 13
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*c%-*.*c|\n", 20, -10, 'Z', 10, -5, 'A');
	printf("YOUR: |");
	ft_printf("%-*.*c%-*.*c", 20, -10, 'Z', 10, -5, 'A');
	printf("|\n");

	printf("\n~~~~~~~~~~Basic Test End!~~~~~~~~~~~\n");
	return ;
}

static void		basic_test_one_arg(void)
{
	size_t	test_count = 1;

	printf("\n~~~~~~~~~~Basic Test Start~~~~~~~~~~\n");

	// 01
	printf("test: %zu\n", test_count++);
	printf("NEED: |%c|\n", 'Z');
	printf("YOUR: |");
	ft_printf("%c", 'Z');
	printf("|\n");

	// 02
	printf("test: %zu\n", test_count++);
	printf("NEED: |%10c|\n", 'Z');
	printf("YOUR: |");
	ft_printf("%10c", 'Z');
	printf("|\n");

	// 03
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-10c|\n", 'Z');
	printf("YOUR: |");
	ft_printf("%-10c", 'Z');
	printf("|\n");

	// 04
	printf("test: %zu\n", test_count++);
	printf("NEED: |%010c|\n", 'Z');
	printf("YOUR: |");
	ft_printf("%010c", 'Z');
	printf("|\n");

	// 05
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*c|\n", 10, 'Z');
	printf("YOUR: |");
	ft_printf("%*c", 10, 'Z');
	printf("|\n");

	// 06
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*c|\n", -10, 'Z');
	printf("YOUR: |");
	ft_printf("%*c", -10, 'Z');
	printf("|\n");

	// 07
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*c|\n", 20, 'Z');
	printf("YOUR: |");
	ft_printf("%-*c", 20, 'Z');
	printf("|\n");

	// 08
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*c|\n", 20, 'Z');
	printf("YOUR: |");
	ft_printf("%0*c", 20, 'Z');
	printf("|\n");

	// 09
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.50c|\n", 20, 'Z');
	printf("YOUR: |");
	ft_printf("%*.50c", 20, 'Z');
	printf("|\n");

	// 10
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.5c|\n", 20, 'Z');
	printf("YOUR: |");
	ft_printf("%*.5c", 20, 'Z');
	printf("|\n");

	// 11
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*c|\n", 20, 50, 'Z');
	printf("YOUR: |");
	ft_printf("%-*.*c", 20, 50, 'Z');
	printf("|\n");

	// 12
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*c|\n", 20, 5, 'Z');
	printf("YOUR: |");
	ft_printf("%-*.*c", 20, 5, 'Z');
	printf("|\n");

	// 13
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*c|\n", 20, -10, 'Z');
	printf("YOUR: |");
	ft_printf("%-*.*c", 20, -10, 'Z');
	printf("|\n");

	printf("\n~~~~~~~~~~Basic Test End!~~~~~~~~~~~\n");
	return ;
}

int				test_spec_c(void)
{
	// basic_test_one_arg();
	basic_test_two_arg();
	return (0);
}