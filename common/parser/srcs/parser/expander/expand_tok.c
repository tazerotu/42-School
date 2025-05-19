/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:56:29 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/16 16:41:52 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static char	*expand_nonquote(char *src, t_pipe *pipe,
	int split_start, int i)
{
	char	*tmp;
	char	*processed;

	tmp = ft_substr(src, split_start, (size_t) i - split_start);
	processed = expander(tmp, pipe->envp, pipe);
	free(tmp);
	return (processed);
}

static char	*expand_simple_quote(char *src,
	int *split_start, int *i)
{
	char	*tmp;
	size_t	len;

	*split_start = *i + 1;
	*i = skip_past_quote_end(src, *i, src[*i]);
	len = (size_t)(*i) - (*split_start) - 1;
	tmp = ft_substr(src, *split_start, len);
	*split_start = *i;
	return (tmp);
}

static char	*expand_double_quote(char *src, t_pipe *pipe,
	int *split_start, int *i)
{
	char	*tmp;
	char	*processed;
	size_t	len;

	*split_start = *i + 1;
	*i = skip_past_quote_end(src, *i, src[*i]);
	len = (size_t)(*i) - (*split_start) - 1;
	tmp = ft_substr(src, *split_start, len);
	processed = expander(tmp, pipe->envp, pipe);
	free(tmp);
	*split_start = *i;
	return (processed);
}

static void	expand_token2_init(int *i, int *split_start, int *tmp_idx)
{
	*tmp_idx = 0;
	*i = 0;
	*split_start = 0;
}

void	expand_token2(char *str, t_pipe *pipe, char **tmp)
{
	int		i;
	int		tmp_idx;
	int		split_start;

	expand_token2_init(&i, &split_start, &tmp_idx);
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (split_start < i)
				tmp[tmp_idx++] = expand_nonquote(str, pipe, split_start, i);
			tmp[tmp_idx++] = expand_simple_quote(str, &split_start, &i);
		}
		else if (str[i] == '"')
		{
			if (split_start < i)
				tmp[tmp_idx++] = expand_nonquote(str, pipe, split_start, i);
			tmp[tmp_idx++] = expand_double_quote(str, pipe, &split_start, &i);
		}
		else
			++i;
	}
	if (split_start < i)
		tmp[tmp_idx] = expand_nonquote(str, pipe, split_start, i);
}
