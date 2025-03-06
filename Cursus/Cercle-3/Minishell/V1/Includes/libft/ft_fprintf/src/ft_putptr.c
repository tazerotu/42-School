/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:05:42 by ttas              #+#    #+#             */
/*   Updated: 2025/03/04 11:07:05 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fprintf.h"

static int	ft_hexa_ptr(int fd, size_t decimal_number, char *base)
{
	unsigned int	i;

	i = 0;
	if (decimal_number >= 16)
	{
		i += ft_hexa_ptr(fd, decimal_number / 16, base);
	}
	ft_putchar_fd_fprintf(fd, base[decimal_number % 16]);
	i++;
	return (i);
}

int	ft_putptr_fd(int fd, size_t *ptr)
{
	int	i;

	if (ptr == NULL)
	{
		ft_putstr_fd_fprintf(fd, "(nil)");
		return (5);
	}
	i = ft_putstr_fd_fprintf(fd, "0x");
	i += ft_hexa_ptr(fd, (size_t)ptr, "0123456789abcdef");
	return (i);
}
