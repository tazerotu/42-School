/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:35:19 by clai-ton          #+#    #+#             */
/*   Updated: 2025/03/05 17:33:40 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

//TODO: $?
//Currently the behavior SHOULD be that it doesn't find a matching var

/* 
* Returns the value of the environment variable written as $VARIABLE.
* Also handles $?, the exit code of the previous command,
* but not $$ and $1 (or other numbers), which will be handled as plain text.
* Will return NULL if the variable is not set.
*/
static char	*fill_var(int *i, char *str)
{
	char	*var_name;
	char	*value;
	int		sub_start;

	++(*i);
	sub_start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		++(*i);
	var_name = ft_substr(str, sub_start, *i - sub_start);
	value = ft_strdup(getenv(var_name));
	free(var_name);
	return (value);
}

static int	fill_split(char **split_str, char *str)
{
	int	i;
	int	sub_start;
	int	j;

	i = -1;
	sub_start = 0;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '$' && (ft_isalpha(str[i + 1]) || str[i + 1] == '?'))
		{
			if (i != sub_start)
				split_str[j++] = ft_substr(str, sub_start, i - sub_start);
			split_str[j] = fill_var(&i, str);
			if (split_str[j])
				++j;
			sub_start = i;
			--i;
		}
	}
	if (sub_start <= i)
		split_str[j] = ft_substr(str, sub_start, i - sub_start);
	return (j);
}

static int	count_split_token(char *str)
{
	int		i;
	int		count;

	i = 0;
	if (str[i] == '$' && (ft_isalpha(str[i + 1]) || str[i + 1] == '?'))
		count = 0;
	else
		count = 1;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalpha(str[i + 1]) || str[i + 1] == '?'))
		{
			++count;
			++i;
			if (str[i] == '?')
				++i;
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				++i;
			if (str[i] && str[i] != '$')
				++count;
			continue ;
		}
		++i;
	}
	return (count);
}

void	replace_var(t_list	**tok_lst)
{
	t_list	*cur_lst;
	t_tok	*tok;
	int		count;
	char	**split_str;
	int		i;

	cur_lst = *tok_lst;
	while (cur_lst)
	{
		tok = (t_tok *) cur_lst->content;
		if (tok->quote_type == Q_WITHOUT || tok->quote_type == Q_DOUBLE)
		{
			count = count_split_token(tok->str);
			split_str = ft_calloc(count + 1, sizeof(char *));
			count = fill_split(split_str, tok->str) + 1;
			free(tok->str);
			tok->str = ft_strjoin_multi(count, split_str, NULL);
			i = 0;
			while (split_str[i])
				free(split_str[i++]);
			free(split_str);
		}
		cur_lst = cur_lst->next;
	}
}
