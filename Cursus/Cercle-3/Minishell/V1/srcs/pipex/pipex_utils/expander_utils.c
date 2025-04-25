/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:13 by ttas              #+#    #+#             */
/*   Updated: 2025/04/25 13:39:10 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static int	ft_isalpha_upper(int c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

static int	ft_isalnum_upper(int c)
{
	if (ft_isalpha_upper(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}

int	expander_syntax(char *str, int *end)
{
	int	i;

	i = *end;
	if (!ft_isalpha_upper(str[i]) && str[i] != '_')
		return (-1);
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isalnum_upper(str[i]) && str[i] != '_')
			return (-2);
		i++;
	}
	return (i);
}
