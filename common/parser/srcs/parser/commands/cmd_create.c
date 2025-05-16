/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:54:55 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/28 13:51:40 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/parser.h"

int	add_cmd(t_cmd **cur_cmd)
{
	t_cmd	*next_cmd;

	next_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!next_cmd)
		return (RET_MALLOC_ERR);
	(*cur_cmd)->next = next_cmd;
	(*cur_cmd) = next_cmd;
	return (RET_PROCESSED);
}

int	create_cmd_list(t_dblst **words, t_cmd **cmds)
{
	t_dblst	*cur_word;
	t_cmd	*cur_cmd;
	
	cur_word = ft_dblstfirst(*words);
	cur_cmd = *cmds;
	cur_cmd->next = NULL;
	while (cur_word)
	{
		if (word_is_pipe((char *) cur_word->content))
		{
			if (add_cmd(&cur_cmd) == RET_MALLOC_ERR)
				return (RET_MALLOC_ERR);
		}
		cur_word = cur_word->next;
	}
	return (RET_PROCESSED);
}
