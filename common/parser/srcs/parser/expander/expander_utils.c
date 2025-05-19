/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:13 by ttas              #+#    #+#             */
/*   Updated: 2025/05/16 14:43:48 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int	ft_isalpha_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_special_dollar_char(char c)
{
	return (ft_isspace((int) c) || c == '$' || c == '\''
		|| c == '"' || c == '<' || c == '>' || c == '|' || c == '\0');
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
	char	*name;

	if (!str[++expander->end] || !ft_isalpha_upper(str[expander->end++]))
		return (NULL);
	while (str[expander->end] && !is_special_dollar_char(str[expander->end]))
		++expander->end;
	name = ft_substr(str, expander->start, expander->end - expander->start);
	return (name);
}
