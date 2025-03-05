/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:05:10 by clai-ton          #+#    #+#             */
/*   Updated: 2025/03/05 16:20:27 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

static size_t	token_new_size(char *src)
{
	int		was_word;
	size_t	src_i;
	size_t	dest_size;

	was_word = 0;
	src_i = 0;
	dest_size = 1;
	while (src[src_i])
	{
		if (src[src_i] != ' ')
		{
			was_word = 1;
			++dest_size;
		}
		else
		{
			if (was_word)
				++dest_size;
			was_word = 0;
		}
		++src_i;
	}
	return (dest_size);
}

char	*ft_trim_token(char *src)
{
	size_t	src_i;
	size_t	dest_i;
	size_t	dest_size;
	char	*dest;

	src_i = 0;
	dest_i = 0;
	dest_size = token_new_size(src);
	if (ft_strlen(src) == dest_size - 1)
		return (NULL);
	dest = malloc(dest_size * sizeof(char));
	while (src[src_i])
	{
		while (src[src_i] && src[src_i] == ' ')
			++src_i;
		if (src[src_i] && dest_i > 0 && dest[dest_i - 1] != ' '
			&& src_i > 0 && src[src_i - 1] == ' ')
			dest[dest_i++] = ' ';
		if (src[src_i])
			dest[dest_i++] = src[src_i++];
	}
	dest[dest_i] = '\0';
	return (dest);
}

void	trim_spaces(t_list	**tok_lst)
{
	t_list	*cur_lst;
	t_tok	*tok;
	char	*new;

	cur_lst = *tok_lst;
	while (cur_lst)
	{
		tok = (t_tok *) cur_lst->content;
		if (tok->quote_type == Q_WITHOUT)
		{
			new = ft_trim_token(tok->str);
			if (new)
			{
				free(tok->str);
				tok->str = new;
			}
		}
		cur_lst = cur_lst->next;
	}
}
