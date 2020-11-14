/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:25:18 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/03 14:41:31 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	bytes[2];

	if (fd < 0)
		return ;
	if (c < 0)
	{
		c = (unsigned char)c;
		bytes[1] = (c & 0x3F) | 0x80;
		bytes[0] = ((c & 0xC0) >> 6) | 0xC0;
		write(fd, bytes, 2);
		return ;
	}
	write(fd, &c, 1);
}
