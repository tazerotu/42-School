/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:13 by ttas              #+#    #+#             */
/*   Updated: 2025/05/29 12:07:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

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

	if (!str[++expander->end] || !ft_isalpha(str[expander->end++]))
		return (NULL);
	while (str[expander->end] && !is_special_dollar_char(str[expander->end]))
		++expander->end;
	name = ft_substr(str, expander->start, expander->end - expander->start);
	return (name);
}

char	*clean_expand(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] >= 32 && str[i] <= 126)
			j++;
	ret = malloc(sizeof(char) * j + 1);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] >= 32 && str[i] <= 126)
			ret[j++] = str[i];
	ret[j] = '\0';
	return (ret);
}

/*static int	count_tokens(char **tok)
{
	int	i;

	i = 0;
	while (tok[i])
		++i;
	return (i);
}

void	post_expander_split(t_cmd *cmds)
{
	int		i;
	char	*tmp;

	while (cmds)
	{
		tmp = ft_strjoin_multi(count_tokens(cmds->arg_tok), cmds->arg_tok, " ");
		printf("tmp=%s\n", tmp);
		i = 0;
		while (cmds->arg_tok[i])
			free(cmds->arg_tok[i++]);
		free(cmds->arg_tok);
		cmds->arg_tok = ft_split_set(tmp, " ");
		free(tmp);
		cmds = cmds->next;
	}
}*/
