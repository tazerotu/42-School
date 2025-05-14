/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:13 by ttas              #+#    #+#             */
/*   Updated: 2025/05/02 09:14:11 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static int	ft_isalpha_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

// Function to verify the syntax of an environment variable in a string
// And return the variable if the syntax is correct
// returns NULL if incorrect syntax and skips to next character
// examples :
// $USER  -> ttas
// $9USER -> USER
// $USER9 -> NULL
// $USEr  -> NULL
// $USERt -> NULL
char	*verify_syntax(char *str, t_expander *expander)
{
	char	*value;

	expander->end++;
	if (ft_isalpha_upper(str[expander->end++]) == 0)
		return (NULL);
	expander->end++;
	while (str[expander->end] && ft_isspace(str[expander->end]) == 0)
		expander->end++;
	value = ft_substr(str, expander->start,
			(expander->end + 1) - expander->start);
	return (value);
}
