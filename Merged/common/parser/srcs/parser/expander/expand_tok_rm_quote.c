/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tok_rm_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:19:46 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/16 10:37:50 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

//todo check something about the split count
char	*expand_tokens3(char *str, t_env *envp, t_pipe *pipe)
{
	unsigned int	i;
	unsigned int	tmp_idx;
	unsigned int	split_start;
	char			**tmp;
	unsigned int	split_count;
	char			*ret_str;
	char			*tmp_ret;
printf("exp tok 3 received str: %s\n", str);
	i = 0;
	split_start = 0;
	split_count = count_split_quotes(str);
printf("split into %u\n", split_count);
	tmp = ft_calloc(split_count, sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp_idx = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (split_start < i)
			{
				tmp[tmp_idx] = ft_substr(str, split_start,
					(size_t) i - split_start);
printf("extracted: %s\n", tmp[tmp_idx]);
				tmp_ret = expander(tmp[tmp_idx], envp, pipe);
printf("expander result: %s\n", tmp_ret);
				free(tmp[tmp_idx]);
printf("tmp_idx=%u\n", tmp_idx);
				tmp[tmp_idx++] = tmp_ret;
			}
			split_start = i + 1;
printf("pre-skip quote i=%u\n", i);
			i = skip_past_quote_end(str, i, str[i]);
printf("post skip quote i=%u\n", i);
			tmp[tmp_idx++] = ft_substr(str, split_start,
				(size_t) i - split_start - 1);
			split_start = i;
		}
		else if (str[i] == '"')
		{
			if (split_start < i)
			{
				tmp[tmp_idx] = ft_substr(str, split_start,
					(size_t) i - split_start);
printf("extracted: %s\n", tmp[tmp_idx]);
				tmp_ret = expander(tmp[tmp_idx], envp, pipe);
				free(tmp[tmp_idx]);
				tmp[tmp_idx++] = tmp_ret;
printf("post expansion: %s\n", tmp[tmp_idx - 1]);
			}
			split_start = i + 1;
			i = skip_past_quote_end(str, i, str[i]);
			tmp[tmp_idx] = ft_substr(str, split_start,
				(size_t) i - split_start - 1);
printf("extracted: %s\n", tmp[tmp_idx]);
			tmp_ret = expander(tmp[tmp_idx], envp, pipe);
			free(tmp[tmp_idx]);
			tmp[tmp_idx++] = tmp_ret;
printf("post expansion: %s\n", tmp[tmp_idx - 1]);
			split_start = i;
		}
		else
			++i;
	}
	if (split_start < i)
	{
		tmp[tmp_idx] = ft_substr(str, split_start, (size_t) i - split_start);
printf("extracted: %s\n", tmp[tmp_idx]);
		tmp_ret = expander(tmp[tmp_idx], envp, pipe);
		free(tmp[tmp_idx]);
		tmp[tmp_idx] = tmp_ret;
		++tmp_idx;
printf("post expansion: %s\n", tmp[tmp_idx - 1]);
	}
	free(str);
	ret_str = ft_strjoin_multi(split_count, tmp, NULL);
	tmp_idx = 0;
	while (tmp[tmp_idx])
		free(tmp[tmp_idx++]);
	free(tmp);
	return (ret_str);
}

static int	rm_empty_quote_tok(char *tok)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tok[j])
	{
		if ((tok[j] == '\'' || tok[j] == '"') && tok[j] == tok[j + 1])
			j += 2;
		tok[i] = tok[j];
		++i;
		++j;
	}
	tok[i] = '\0';
	return (RET_PROCESSED);
}

//the main expander function
//todo check if received null
void	expand_tok_rm_quote(t_cmd *cmd, t_env *envp, t_pipe *pipe)
{
	int	i;

	while (cmd)
	{
		i = 0;
		while (cmd->arg_tok[i])
		{
			printf("input %s\n", cmd->arg_tok[i]);
			rm_empty_quote_tok(cmd->arg_tok[i]);
			cmd->arg_tok[i] = expand_tokens3(cmd->arg_tok[i], envp, pipe);
			printf("output %s\n", cmd->arg_tok[i]);
			++i;
		}
		i = 0;
		while (cmd->redir_tok[i])
		{
			printf("input %s\n", cmd->redir_tok[i]);
			rm_empty_quote_tok(cmd->redir_tok[i]);
			cmd->redir_tok[i] = expand_tokens3(cmd->redir_tok[i], envp, pipe);
			printf("output %s\n", cmd->redir_tok[i]);
			++i;
		}
		cmd = cmd->next;
	}
}