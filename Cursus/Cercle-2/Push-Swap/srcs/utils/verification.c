/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:00:35 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 12:00:10 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	checker(char **argv, int argc)
{
	char	**tab;

	if (argc < 2)
		error_message(1);
	else if (!argv[1][0])
		error_message(2);
	else if (argc == 2)
	{
		if (count_words(argv[1], ' ') == 1)
			error_message(1);
		tab = ft_split(argv[1], ' ');
		check_args(tab);
		if (is_sorted_str(tab) == SUCCESS)
		{
			ft_free(tab);
			return (SUCCESS);
		}
	}
	else
	{
		check_args(argv + 1);
		if (is_sorted_str(argv + 1) == SUCCESS)
			return (SUCCESS);
	}
	if (argc == 2)
		ft_free(tab);
	return (FAILURE);
}

static void	check_overflow(char *str)
{
	long			tmp;
	unsigned int	i;
	int				is_negative;

	i = 0;
	is_negative = 0;
	tmp = 0;
	if (str[i] == '-')
	{
		i++;
		is_negative = 1;
	}
	while (str[i])
	{
		tmp = tmp * 10 + (str[i] - '0');
		i++;
	}
	if (tmp > 2147483648 && is_negative == 1)
		error_message(4);
	else if (tmp > 2147483647 && is_negative == 0)
		error_message(4);
}

static void	check_double(char **str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	check_overflow(str[i]);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			check_overflow(str[j]);
			if (!ft_strcmp(str[i], str[j]))
				error_message(3);
			j++;
		}
		i++;
	}
}

void	check_args(char **str)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '+' || str[i][j] == '-')
				j++;
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				error_message(2);
			j++;
		}
		i++;
	}
	check_double(str);
}
