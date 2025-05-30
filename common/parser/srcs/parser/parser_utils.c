/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:19:16 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/30 10:55:01 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	insert_node_before(t_dblst *cur, char *substr)
{
	ft_dblstinsert_before(cur, ft_dblstnew(substr));
	if (!cur->prev)
		return (RET_MALLOC_ERR);
	return (RET_PROCESSED);
}

size_t	count_occurences(char *str, int i)
{
	size_t	occ;

	occ = 1;
	while (str[i + occ] == str[i])
		++occ;
	return (occ);
}

static void	remove_empty_args2(char **tok)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tok[i] && tok[j])
	{
		while (tok[j] && tok[j][0] == '\0')
		{
			free(tok[j]);
			tok[j] = NULL;
			++j;
		}
		tok[i] = tok[j];
		++i;
		++j;
	}
	while (i < j)
		tok[i++] = NULL;
}

void	remove_empty_args(t_cmd *cmds)
{
	while (cmds)
	{
		remove_empty_args2(cmds->arg_tok);
		cmds = cmds->next;
	}
}
