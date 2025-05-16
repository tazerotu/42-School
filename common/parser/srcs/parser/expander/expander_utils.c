/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:13 by ttas              #+#    #+#             */
/*   Updated: 2025/05/14 18:36:31 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static int	ft_isalpha_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int	is_special_char(char c)
{
	return (ft_isspace((int) c) || c == '$' || c == '\''
		|| c == '"' || c == '<' || c == '>' || c == '|' || c == '?');
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

	++expander->end;
	if (!str[expander->end] || !ft_isalpha_upper(str[expander->end]))
		return (NULL);
	++expander->end;
	while (str[expander->end] && !is_special_char(str[expander->end]))
		++expander->end;
	value = ft_substr(str, expander->start,
			expander->end - expander->start);
printf("var name: %s\n", value);//$USER$USER takes the mid $ with the start
	return (value);
}

unsigned int	skip_past_quote_end(char *str, int i, char quote)
{
	++i;
	while (str[i] && str[i] != quote)
		++i;
	if (str[i])
		++i;
	return (i);
}

int	count_split_quotes(char *str)
{
	int				r;
	unsigned int	i;
	int				was_quote;

	i = 0;
	r = 0;
	was_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (!was_quote && i > 0)
				++r;
			if (str[i] != str[i + 1])
				++r;
			i = skip_past_quote_end(str, i, str[i]);
			was_quote = 1;
		}
		else
		{
			was_quote = 0;
			++i;
		}
	}
	if (!was_quote)
		++r;
	return (r);
}
