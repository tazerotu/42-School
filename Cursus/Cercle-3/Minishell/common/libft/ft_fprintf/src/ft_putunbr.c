/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:46:20 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 10:27:40 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fprintf.h"

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

int	ft_putunbr_fd_fprintf(int fd, unsigned int n)
{
	int	i;

	i = ft_num_len(n);
	if (n >= 10)
	{
		ft_putunbr_fd_fprintf(fd, n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd_fprintf(fd, n + 48);
	}
	return (i);
}
