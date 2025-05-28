/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:47:23 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/28 18:15:45 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

int	skip_past_quote_end(char *str, int i, char quote)
{
	++i;
	while (str[i] && str[i] != quote)
		++i;
	if (str[i])
		++i;
	return (i);
}

static void	count_split_quotes_loop(char *str, int *i, int *r, int *was_quote)
{
	if (str[*i] == '\'' || str[*i] == '"')
	{
		if (!*was_quote && *i > 0)
			++(*r);
		if (str[*i] != str[*i + 1])
			++(*r);
		*i = skip_past_quote_end(str, *i, str[*i]);
		*was_quote = 1;
	}
	else
	{
		*was_quote = 0;
		++(*i);
	}
}

int	count_split_quotes(char *str)
{
	int	r;
	int	i;
	int	was_quote;

	i = 0;
	r = 0;
	was_quote = 0;
	while (str[i])
		count_split_quotes_loop(str, &i, &r, &was_quote);
	if (!was_quote)
		++r;
	return (r);
}

int	rm_empty_quote_tok(char *tok)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tok[j])
	{
		if ((tok[j] == '\'' || tok[j] == '"') && tok[j] == tok[j + 1])
			j += 2;
		else
		{
			tok[i] = tok[j];
			++i;
			++j;
		}
	}
	while (i < j)
		tok[i++] = '\0';
	return (RET_PROCESSED);
}
