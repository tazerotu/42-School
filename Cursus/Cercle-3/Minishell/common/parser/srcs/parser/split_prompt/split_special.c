/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:14:02 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/28 12:20:40 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static void	manage_quote(char c, int *q_type, int *i)
{
	if (c == '"')
	{
		if (*q_type == Q_NONE)
			*q_type = Q_DOUBLE;
		else if (*q_type == Q_DOUBLE)
			*q_type = Q_NONE;
	}
	else if (c == '\'')
	{
		if (*q_type == Q_NONE)
			*q_type = Q_SIMPLE;
		else if (*q_type == Q_SIMPLE)
			*q_type = Q_NONE;
	}
	++(*i);
}

static int	split_special_char3(t_dblst *cur, int *i, int *start)
{
	char	*word;
	size_t	len;
	size_t	occ;

	word = (char *) cur->content;
	occ = count_occurences(word, *i);
	len = ft_strlen(word);
	if ((word[*i] == '|' && occ > 1) || occ > 2)
		return (RET_SYNTAX_ERR);
	if (occ == len)
	{
		*i += (int) occ;
		*start = *i;
		return (RET_NOTHING_DONE);
	}
	if (*i > *start)
		if (insert_node_before(cur, ft_substr(word, *start, *i - *start))
			== RET_MALLOC_ERR)
			return (RET_MALLOC_ERR);
	if (insert_node_before(cur, ft_substr(word, *i, occ)) == RET_MALLOC_ERR)
		return (RET_MALLOC_ERR);
	*i += (int) occ;
	*start = *i;
	return (RET_PROCESSED);
}

static int	split_special_char2(t_dblst *cur, char *word, int q_type)
{
	int		i;
	int		start;
	int		ret;

	i = 0;
	start = 0;
	ret = RET_NOTHING_DONE;
	while (word[i])
	{
		if (word[i] == '"' || word[i] == '\'')
			manage_quote(word[i], &q_type, &i);
		else if (q_type == Q_NONE
			&& (word[i] == '|' || word[i] == '>' || word[i] == '<'))
		{
			ret = split_special_char3(cur, &i, &start);
			if (ret != RET_PROCESSED && ret != RET_NOTHING_DONE)
				return (ret);
		}
		else
			++i;
	}
	if (i > start && (size_t) i <= ft_strlen(word) && ret != RET_NOTHING_DONE)
		ret = insert_node_before(cur, ft_substr(word, start, i - start));
	return (ret);
}

/*
* Splits tokens according to the following special-meaning strings:
* <, >, <<, >>, and |.
* In case there were none of these strings, the function will create
* a copy of the current token then delete the original.
*/
int	split_special_char(t_dblst **tok_dblst)
{
	t_dblst	*cur;
	t_dblst	*next;
	char	*word;
	int		ret;

	cur = *tok_dblst;
	while (cur)
	{
		next = cur->next;
		word = (char *) cur->content;
		if (!word[0])
			return (RET_NOTHING_DONE);
		ret = split_special_char2(cur, word, Q_NONE);
		if (ret != RET_PROCESSED && ret != RET_NOTHING_DONE)
			return (ret);
		if (!next)
			*tok_dblst = ft_dblstfirst(cur);
		if (ret != RET_NOTHING_DONE)
			ft_dblstdelone(cur, free);
		cur = next;
	}
	return (RET_PROCESSED);
}
