/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tok_rm_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:19:46 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/26 17:21:00 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static char	*expand_token(char *str, t_pipe *pipe)
{
	char	**tmp;
	int		split_count;
	char	*ret_str;
	int		i;

	split_count = count_split_quotes(str);
	tmp = ft_calloc(split_count, sizeof(char *));
	if (!tmp)
		return (NULL);
	expand_token2(str, pipe, tmp);
	free(str);
	ret_str = ft_strjoin_multi(split_count, tmp, NULL);
	i = 0;
	while (i < split_count)
		free(tmp[i++]);
	free(tmp);
	return (ret_str);
}

static int	expand_tok_rm_quote2(t_cmd *cmds, char **tokens, t_pipe *pipe)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		rm_empty_quote_tok(tokens[i]);
		if (word_is_heredoc(tokens[i]))
		{
			i += 2;
			continue ;
		}
		tokens[i] = expand_token(tokens[i], pipe);
		if (!tokens[i])
		{
			while (tokens[i])
				free(tokens[i++]);
			free_cmds(cmds);
			error_message_parsing(RET_MALLOC_ERR, "expanding");
			return (RET_MALLOC_ERR);
		}
		++i;
	}
	return (RET_PROCESSED);
}

int	expand_tok_rm_quote(t_cmd *cmd, t_pipe *pipe)
{
	int		ret_val;
	t_cmd	*first_cmd;

	first_cmd = cmd;
	while (cmd)
	{
		ret_val = expand_tok_rm_quote2(first_cmd, cmd->arg_tok, pipe);
		if (ret_val != RET_PROCESSED)
			return (ret_val);
		ret_val = expand_tok_rm_quote2(first_cmd, cmd->redir_tok, pipe);
		if (ret_val != RET_PROCESSED)
			return (ret_val);
		cmd = cmd->next;
	}
	return (RET_PROCESSED);
}
