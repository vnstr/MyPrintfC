/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test_arg_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:49:54 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/15 01:02:22 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	basic_test_one_arg(void)
{
	size_t	test_count = 1;

	printf("\n~~~~~~~~~~Basic Test Start~~~~~~~~~~\n");

	// 01
	printf("test: %zu\n", test_count++);
	printf("NEED: |%s|\n", "ABCD");
	printf("YOUR: |");
	ft_printf("%s", "ABCD");
	printf("|\n");

	// 02
	printf("test: %zu\n", test_count++);
	printf("NEED: |%20s|\n", "ABCD");
	printf("YOUR: |");
	ft_printf("%20s", "ABCD");
	printf("|\n");

	// 03
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-20s|\n", "ABCD");
	printf("YOUR: |");
	ft_printf("%-20s", "ABCD");
	printf("|\n");

	// 04
	printf("test: %zu\n", test_count++);
	printf("NEED: |%020s|\n", "ABCD");
	printf("YOUR: |");
	ft_printf("%020s", "ABCD");
	printf("|\n");

	// 05
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*s|\n", 15, "ABCD");
	printf("YOUR: |");
	ft_printf("%*s", 15, "ABCD");
	printf("|\n");

	// 06
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*s|\n", -15, "ABCD");
	printf("YOUR: |");
	ft_printf("%*s", -15, "ABCD");
	printf("|\n");

	// 07
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*s|\n", 15, "ABCD");
	printf("YOUR: |");
	ft_printf("%-*s", 15, "ABCD");
	printf("|\n");

	// 08
	printf("test: %zu\n", test_count++);
	printf("NEED: |%0*s|\n", 15, "ABCD");
	printf("YOUR: |");
	ft_printf("%0*s", 15, "ABCD");
	printf("|\n");

	// 09
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.50s|\n", 15, "ABCD");
	printf("YOUR: |");
	ft_printf("%*.50s", 15, "ABCD");
	printf("|\n");

	// 10
	printf("test: %zu\n", test_count++);
	printf("NEED: |%*.2s|\n", 15, "ABCD");
	printf("YOUR: |");
	ft_printf("%*.2s", 15, "ABCD");
	printf("|\n");

	// 11
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*s|\n", 15, 50, "ABCD");
	printf("YOUR: |");
	ft_printf("%-*.*s", 15, 50, "ABCD");
	printf("|\n");

	// 12
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*s|\n", 15, 2, "ABCD");
	printf("YOUR: |");
	ft_printf("%-*.*s", 15, 2, "ABCD");
	printf("|\n");

	// 13
	printf("test: %zu\n", test_count++);
	printf("NEED: |%-*.*s|\n", 15, -50, "ABCD");
	printf("YOUR: |");
	ft_printf("%-*.*s", 15, -50, "ABCD");
	printf("|\n");

	printf("\n~~~~~~~~~~Basic Test End!~~~~~~~~~~~\n");

	return ;
}

void		basic_test_arg_s(void)
{
	basic_test_one_arg();
	return ;
}