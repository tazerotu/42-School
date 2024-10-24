/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:46:20 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 09:18:09 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdprintf.h"

static int	ft_num_len(unsigned int n)
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

int	ft_putunbr_fd(int fd, unsigned int n)
{
	int	i;

	i = ft_num_len(n);
	if (n >= 10)
	{
		ft_putunbr_fd(fd, n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd(fd, n + 48);
	}
	return (i);
}
