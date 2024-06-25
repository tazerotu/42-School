/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:18:22 by ttas              #+#    #+#             */
/*   Updated: 2024/03/21 09:37:14 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		i;
	char	signe;
	int		resultat;

	resultat = 0;
	signe = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				signe *= -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			resultat = (10 * resultat + (str[i] - '0'));
			i++;
		}
		return (resultat * signe);
	}
	return (0);
}
