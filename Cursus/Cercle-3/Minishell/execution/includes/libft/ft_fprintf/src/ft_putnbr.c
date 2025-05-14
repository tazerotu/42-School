/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:46:03 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 10:27:45 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fprintf.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_putnbr_fd_fprintf(int fd, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd_fprintf(fd, '-');
		n = -n;
		i++;
	}
	i += ft_num_len(n);
	if (n >= 10)
	{
		ft_putnbr_fd_fprintf(fd, n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd_fprintf(fd, n + 48);
	}
	return (i);
}
