/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:05:42 by ttas              #+#    #+#             */
/*   Updated: 2024/05/14 11:24:15 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_hexa_ptr(size_t decimal_number, char *base)
{
	unsigned int	i;

	i = 0;
	if (decimal_number >= 16)
	{
		i += ft_hexa_ptr(decimal_number / 16, base);
	}
	ft_putchar(base[decimal_number % 16]);
	i++;
	return (i);
}

int	ft_putptr(size_t *ptr)
{
	int	i;

	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	i = ft_putstr("0x");
	i += ft_hexa_ptr((size_t)ptr, "0123456789abcdef");
	return (i);
}
