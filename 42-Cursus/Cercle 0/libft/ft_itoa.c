/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:03:33 by ttas              #+#    #+#             */
/*   Updated: 2024/05/03 14:39:17 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isneg(int *n, int *neg, int *tmp)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*neg = -1;
		*tmp = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*neg = -1;
		*n = *n * -1;
		*tmp = 0;
	}
	else if (*n >= 0)
	{
		*neg = 1;
		*tmp = 0;
	}
}

static int	ft_itoa_len(int n)
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

static void	ft_itoa_write(char *str, int len, int n, int tmp)
{
	while (n > 9)
	{
		str[len--] = (n % 10) + '0' + tmp;
		n = n / 10;
		tmp = 0;
	}
	str[len] = n + '0';
}

char	*ft_itoa(int n)
{
	int		neg;
	int		tmp;
	int		len;
	char	*str;

	ft_isneg(&n, &neg, &tmp);
	len = ft_itoa_len(n);
	if (neg == -1)
	{
		str = malloc((len + 2) * sizeof(char));
		if (!str)
			return (0);
		len++;
		str[0] = '-';
	}
	else
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (0);
	}
	str[len--] = '\0';
	ft_itoa_write(str, len, n, tmp);
	return (str);
}

// static void	ft_is_negative(int *n, int *negative, int *tmp)
// {
// 	if (*n == -2147483648)
// 	{
// 		*n = *n + 1;
// 		*negative = -1;
// 		*tmp = 1;
// 		*n *= -1;
// 	}
// 	else if (*n < 0)
// 	{
// 		*negative = -1;
// 		*n *= -1;
// 	}
// }

// static int	ft_itoa_len(int n)
// {
// 	int	len;

// 	len = 0;
// 	while (n > 9)
// 	{
// 		n = n / 10;
// 		len++;
// 	}
// 	len++;
// 	return (len);
// }

// static void	ft_itoa_write(char *str, int len, int n, int tmp)
// {
// 	while (n > 9)
// 	{
// 		str[len--] = (n % 10) + '0' + tmp;
// 		n = n / 10;
// 		tmp = 0;
// 	}
// 	str[len] = n + '0';
// }

// char	*ft_itoa(int n)
// {
// 	int		negative;
// 	int		tmp;
// 	int		len;
// 	char	*str;

// 	ft_is_negative(&n, &negative, &tmp);
// 	len = ft_itoa_len(n);
// 	if (negative == -1)
// 	{
// 		str = malloc(len + 2 * sizeof(char));
// 		if (!str)
// 			return (NULL);
// 		len++;
// 		str[0] = '-';
// 	}
// 	else
// 	{
// 		str = malloc(len + 1 * sizeof(char));
// 		if (!str)
// 			return (NULL);
// 	}
// 	str[len--] = '\0';
// 	ft_itoa_write(str, len, n, tmp);
// 	return (str);
// }

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648LL));
// 	return (0);
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	int		size;
// 	int		temp_nbr;

// 	size = 0;
// 	temp_nbr = n;
// 	if (n == -2147483648)
// 	{
// 		str = malloc(11);
// 		str = "-2147483648";
// 		return (str);
// 	}
// 	if (n == 0)
// 	{
// 		str = malloc(1);
// 		str[0] = '0';
// 		return (str);
// 	}
// 	if (temp_nbr < 0)
// 	{
// 		n *= -1;
// 		temp_nbr *= -1;
// 		while (temp_nbr > 0)
// 		{
// 			temp_nbr = temp_nbr / 10;
// 			size++;
// 		}
// 		str = malloc((size + 1) * sizeof(char));
// 		str[0] = '-';
// 	}
// 	else
// 		str = malloc(size);
// 	while (n > 0)
// 	{
// 		str[size] = (n % 10) + '0';
// 		n = n / 10;
// 		size--;
// 	}
// 	return (str);
// }
