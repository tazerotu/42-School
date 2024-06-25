/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:53:33 by marvin            #+#    #+#             */
/*   Updated: 2024/06/22 11:53:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	mod;

	mod = 2;
	if (nb <= 1)
		return (0);
	while (mod < nb)
	{
		if (nb % mod == 0)
		{
			return (0);
		}
		mod++;
	}
	return (nb);
}

void	put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 0;
		int num = 0;
		if(av[1][0] == '+')
			i++;
		while (av[1][i] >= '0' && av[1][i] <= '9')
		{
			num = (num * 10) + (av[1][i] - '0');
			i++;
		}
		i = 0;
		int result = 0;
		while (i <= num)
		{
			result += ft_is_prime(i);
			i++;
		}
		put_nbr(result);
	}
	write(1, "\n", 1);
	return 0;
}