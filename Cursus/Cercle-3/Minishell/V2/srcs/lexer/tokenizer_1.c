/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:47:25 by clai-ton          #+#    #+#             */
/*   Updated: 2025/03/05 16:21:06 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

void	del_token_1(void *tok_void)
{
	t_tok	*tok;

	if (!tok_void)
		return ;
	tok = (t_tok *) tok_void;
	free(tok->str);
	free(tok);
}

static t_tok	*create_tok_quote(char *input, int *i, char quote_char)
{
	t_tok	*tok;
	int		start;

	tok = malloc(sizeof(t_tok));
	if (quote_char == '\'')
		tok->quote_type = Q_SIMPLE;
	else if (quote_char == '"')
		tok->quote_type = Q_DOUBLE;
	start = ++(*i);
	while (input[*i] && input[*i] != quote_char)
		++(*i);
	if (!input[*i])
		tok->str = ft_substr(input, start, *i - start);
	else
	{
		tok->str = ft_substr(input, start, *i - start);
		++(*i);
	}
	return (tok);
}

static t_tok	*create_tok_no_quote(char *input, int *i)
{
	t_tok	*tok;
	int		start;

	tok = malloc(sizeof(t_tok));
	tok->quote_type = Q_WITHOUT;
	start = *i;
	while (input[*i] && input[*i] != '\'' && input[*i] != '"')
		++(*i);
	if (!input[*i])
		tok->str = ft_substr(input, start, *i - start);
	else
		tok->str = ft_substr(input, start, *i - start);
	return (tok);
}

static void	ft_tokenize_1_loop(char *input, t_list **tok_lst)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			ft_lstadd_back(tok_lst,
				ft_lstnew(create_tok_quote(input, &i, '\'')));
		else if (input[i] == '"')
			ft_lstadd_back(tok_lst,
				ft_lstnew(create_tok_quote(input, &i, '"')));
		else
			ft_lstadd_back(tok_lst,
				ft_lstnew(create_tok_no_quote(input, &i)));
	}
}

t_list	**ft_tokenize_1(char *input)
{
	t_list	*dummy_node;
	t_list	**tok_lst;
	t_tok	*dummy_tok;

	dummy_tok = malloc(sizeof(t_tok));
	dummy_tok->quote_type = Q_WITHOUT;
	dummy_tok->str = malloc(sizeof(char));
	dummy_tok->str[0] = '\0';
	dummy_node = ft_lstnew(dummy_tok);
	tok_lst = &dummy_node;
	ft_tokenize_1_loop(input, tok_lst);
	if (dummy_node->next)
	{
		tok_lst = &(dummy_node->next);
		ft_lstdelone(dummy_node, del_token_1);
	}
	return (tok_lst);
}
