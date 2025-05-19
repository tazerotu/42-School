/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:52:33 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/19 17:35:56 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	free_words_dblst(t_dblst **words)
{
	ft_dblstclear(*words, free);
	free (words);
	words = NULL;
}

void	free_redir_early(t_cmd *cmd, int redir_count)
{
	int	i;

	i = 0;
	while (i < redir_count)
		free(cmd->redir_tok[i++]);
	free(cmd->redir_tok);
	cmd->redir_tok = NULL;
}

static void	free_cmd_tok(t_cmd *cmd)
{
	int	i;

	if (cmd->arg_tok)
	{
		i = 0;
		while (cmd->arg_tok[i])
			free(cmd->arg_tok[i++]);
		free(cmd->arg_tok);
	}
	if (cmd->redir_tok)
	{
		i = 0;
		while (cmd->redir_tok[i])
			free(cmd->redir_tok[i++]);
		free(cmd->redir_tok);
	}
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*cur;
	t_cmd	*next;

	cur = cmds;
	while (cur)
	{
		next = cur->next;
		free_cmd_tok(cur);
		free(cur);
		cur = next;
	}
	cmds = NULL;
}
