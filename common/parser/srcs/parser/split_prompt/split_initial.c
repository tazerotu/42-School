/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_initial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:01:05 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/28 18:01:07 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static void	split_nonquote_space2(char *input, int *i, int *start)
{
	char	quote;

	while (ft_isspace(input[*i]))
		++(*i);
	*start = *i;
	while (input[*i] && !ft_isspace(input[*i]))
	{
		if (input[*i] == '\'' || input[*i] == '"')
		{
			quote = input[*i];
			++(*i);
			while (input[*i] && input[*i] != quote)
				++(*i);
			if (input[*i])
				++(*i);
		}
		else
			++(*i);
	}
}

int	split_nonquote_space(char *input, t_dblst *tok_dblst)
{
	int		i;
	int		start;
	t_dblst	*node;

	i = 0;
	while (input[i])
	{
		split_nonquote_space2(input, &i, &start);
		if (i > start)
		{
			node = ft_dblstnew(ft_substr(input, start, i - start));
			if (!node)
				return (RET_MALLOC_ERR);
			ft_dblstadd_back(tok_dblst, node);
		}
	}
	return (RET_PROCESSED);
}

int	split_input(char *input, t_dblst **ret_dblst)
{
	t_dblst	*dummy_node;
	int		ret_val;

	dummy_node = ft_dblstnew(ft_strdup(""));
	if (!dummy_node)
		return (RET_MALLOC_ERR);
	ret_val = split_nonquote_space(input, dummy_node);
	if (ret_val == RET_MALLOC_ERR || ret_val == RET_SYNTAX_ERR)
		return (ret_val);
	if (!dummy_node->next)
	{
		*ret_dblst = dummy_node;
		return (RET_NOTHING_DONE);
	}
	*ret_dblst = dummy_node->next;
	ft_dblstdelone(dummy_node, free);
	ret_val = split_special_char(ret_dblst);
	if (ret_val == RET_MALLOC_ERR || ret_val == RET_SYNTAX_ERR)
		return (ret_val);
	return (RET_PROCESSED);
}
