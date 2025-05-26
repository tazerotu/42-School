/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:07:03 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/26 17:25:52 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_dblst	**process_line_split(char *input, t_pipe *pipe)
{
	t_dblst	**words;
	int		ret_val;

	words = malloc(sizeof(t_dblst *));
	if (!words)
	{
		error_message_parsing(RET_MALLOC_ERR, "splitting prompt");
		return (NULL);
	}
	ret_val = split_input(input, words);
	if (ret_val == RET_NOTHING_DONE)
	{
		free_words_dblst(words);
		return (NULL);
	}
	if (ret_val == RET_MALLOC_ERR || ret_val == RET_SYNTAX_ERR)
	{
		free_words_dblst(words);
		error_message_parsing(ret_val, "splitting prompt");
		pipe->exit_status = 2;
		return (NULL);
	}
	return (words);
}

static t_cmd	*process_line_cmds(t_dblst **words)
{
	t_cmd	*cmds;

	cmds = malloc(sizeof(t_cmd));
	if (!cmds)
	{
		free_words_dblst(words);
		error_message_parsing(RET_MALLOC_ERR, "creating commands");
		return (NULL);
	}
	if (create_cmd_list(words, &cmds) == RET_MALLOC_ERR
		|| fill_cmds(words, cmds) == RET_MALLOC_ERR)
	{
		free_words_dblst(words);
		free_cmds(cmds);
		error_message_parsing(RET_MALLOC_ERR, "creating commands");
		return (NULL);
	}
	free_words_dblst(words);
	return (cmds);
}

t_cmd	*process_line(char *input, t_pipe *pipe)
{
	t_dblst	**words;
	t_cmd	*cmds;

	if (check_incorrect_quotes(input))
	{
		error_message_parsing(RET_SYNTAX_ERR, "checking quote validity");
		pipe->exit_status = 2;
		return (NULL);
	}
	words = process_line_split(input, pipe);
	if (!words)
		return (NULL);
	if (check_first_or_last_is_pipe(words) || check_invalid_follow_up(words))
	{
		free_words_dblst(words);
		error_message_parsing(RET_SYNTAX_ERR, "checking the special characters");
		pipe->exit_status = 2;
		return (NULL);
	}
	cmds = process_line_cmds(words);
	if (!cmds)
		return (NULL);
	if (expand_tok_rm_quote(cmds, pipe) != RET_PROCESSED)
		return (NULL);
	return (cmds);
}
