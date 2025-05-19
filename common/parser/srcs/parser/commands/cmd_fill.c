/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:54:45 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/14 18:02:04 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static void	count_words_per_cmd(t_dblst	*first_node,
	int *redir_count, int *arg_count)
{
	t_dblst	*cur_node;
	char	*str;

	cur_node = first_node;
	while (cur_node)
	{
		str = (char *) cur_node->content;
		if (word_is_pipe(str))
			break ;
		else if (word_is_redirection(str))
		{
			*redir_count += 2;
			cur_node = cur_node->next;
		}
		else
			++(*arg_count);
		cur_node = cur_node->next;
	}
}

static int	split_redir(t_dblst *cur_node, t_cmd *cmd, int *redir_count)
{
	char	*dup;
	char	*str;

	str = (char *) cur_node->content;
	dup = ft_strdup(str);
	cmd->redir_tok[*(redir_count)] = dup;
	if (!dup)
	{
		free_redir_early(cmd, *redir_count);
		return (RET_MALLOC_ERR);
	}
	++*(redir_count);
	cur_node = cur_node->next;
	str = (char *) cur_node->content;
	dup = ft_strdup(str);
	cmd->redir_tok[*(redir_count)] = dup;
	if (!dup)
	{
		free_redir_early(cmd, *redir_count);
		return (RET_MALLOC_ERR);
	}
	++*(redir_count);
	return (RET_PROCESSED);
}

/*
* redir_count and arg_count are only parameters because
* of the norm not giving me space. Thank you 42 Norm.
* The function should be called with these values at 0.
*/
static int	split_words_into_cmds(t_dblst **first_node, t_cmd *cmd,
	int redir_count, int arg_count)
{
	t_dblst	*cur_node;
	char	*str;

	cur_node = *first_node;
	while (cur_node)
	{
		str = (char *) cur_node->content;
		if (word_is_pipe(str))
		{
			*first_node = cur_node->next;
			return (RET_PROCESSED);
		}
		else if (word_is_redirection(str) || word_is_heredoc(str))
		{
			if (split_redir(cur_node, cmd, &redir_count) == RET_MALLOC_ERR)
				return (RET_MALLOC_ERR);
			cur_node = cur_node->next;
		}
		else
			cmd->arg_tok[arg_count++] = ft_strdup(str);
		cur_node = cur_node->next;
	}
	*first_node = NULL;
	return (RET_PROCESSED);
}

int	fill_cmds(t_dblst **words, t_cmd *cmd)
{
	t_dblst	*first_node;
	int		redir_count;
	int		arg_count;

	first_node = ft_dblstfirst(*words);
	while (cmd && first_node)
	{
		redir_count = 0;
		arg_count = 0;
		count_words_per_cmd(first_node, &redir_count, &arg_count);
		cmd->arg_tok = ft_calloc(arg_count + 1, sizeof(char *));
		cmd->redir_tok = ft_calloc(redir_count + 1, sizeof(char *));
		if (!cmd->arg_tok || ! cmd->redir_tok)
			return (RET_MALLOC_ERR);
		if (split_words_into_cmds(&first_node, cmd, 0, 0) == RET_MALLOC_ERR)
			return (RET_MALLOC_ERR);
		cmd = cmd->next;
	}
	return (RET_PROCESSED);
}
