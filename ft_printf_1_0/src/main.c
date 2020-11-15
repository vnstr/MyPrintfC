/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:36:33 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/15 20:30:04 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*ptr = "abc";

	ft_printf("10%.50p", 16);
	// basic_test_arg_s();
	// basic_test_arg_c();
	return (0);
}
