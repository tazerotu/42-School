/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:17:39 by ttas              #+#    #+#             */
/*   Updated: 2024/12/03 11:59:07 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(char *nbr)
{
	int		i;
	char	signe;
	int		resultat;

	resultat = 0;
	signe = 1;
	i = 0;
	while (nptr[i])
	{
		i = ft_whitespace((char *)nptr, i);
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				signe *= -1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			resultat = (10 * resultat + (nptr[i] - '0'));
			i++;
		}
		return (resultat * signe);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}