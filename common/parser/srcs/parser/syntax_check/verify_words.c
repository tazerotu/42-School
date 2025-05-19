/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:13:07 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/14 15:27:04 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

int	word_is_heredoc(char *word)
{
	if (!word)
		return (RET_FALSE);
	if (ft_strlen(word) == 2 && word[0] == '<' && word[1] == '<')
		return (RET_TRUE);
	return (RET_FALSE);
}

int	word_is_pipe(char *word)
{
	if (!word)
		return (RET_FALSE);
	if (ft_strlen(word) == 1 && word[0] == '|')
		return (RET_TRUE);
	return (RET_FALSE);
}

int	word_is_redirection(char *word)
{
	size_t	len;

	if (!word)
		return (RET_FALSE);
	if (word[0] == '<' || word[0] == '>')
	{
		len = ft_strlen(word);
		if (len >= 3)
			return (RET_FALSE);
		if (len == 2 && (word[1] == '<' || word[0] != word[1]))
			return (RET_FALSE);
		else if (len == 2 && word[0] == '>' && word[1] == '>')
			return (RET_TRUE);
		return (RET_TRUE);
	}
	return (RET_FALSE);
}

int	word_is_special(char *word)
{
	return (word_is_heredoc(word)
		|| word_is_pipe(word)
		|| word_is_redirection(word));
}

int	check_invalid_follow_up(t_dblst **words)
{
	t_dblst	*cur;
	char	*str;
	int		prev_is_redir;
	int		prev_is_pipe;
	int		cur_is_pipe;

	cur = ft_dblstfirst(*words);
	prev_is_redir = 0;
	prev_is_pipe = 0;
	while (cur)
	{
		str = cur->content;
		cur_is_pipe = word_is_pipe(str);
		if ((prev_is_redir && word_is_special(str))
			|| (prev_is_pipe && cur_is_pipe))
			return (RET_TRUE);
		prev_is_redir = word_is_redirection(str) || word_is_heredoc(str);
		prev_is_pipe = cur_is_pipe;
		cur = cur->next;
	}
	return (RET_FALSE);
}
