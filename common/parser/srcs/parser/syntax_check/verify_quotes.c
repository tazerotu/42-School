/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:25:59 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/28 11:17:34 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static t_quote	*quote_init(void)
{
	t_quote	*quote;

	quote = malloc(sizeof(t_quote));
	quote->last_s = -1;
	quote->last_d = -1;
	quote->s_count = 0;
	quote->d_count = 0;
	return (quote);
}

static int	check_simple(t_quote *quote, int i)
{
	if (quote->d_count % 2 == 0)
		quote->s_count++;
	else
		return (RET_FALSE);
	if (quote->s_count % 2 == 0
		&& quote->last_s < quote->last_d
		&& quote->d_count % 2 != 0)
		return (RET_TRUE);
	quote->last_s = i;
	return (RET_FALSE);
}

static int	check_double(t_quote *quote, int i)
{
	if (quote->s_count % 2 == 0)
		quote->d_count++;
	else
		return (RET_FALSE);
	if (quote->d_count % 2 == 0
		&& quote->last_d < quote->last_s
		&& quote->s_count % 2 != 0)
		return (RET_TRUE);
	quote->last_d = i;
	return (RET_FALSE);
}

/*
* Returns RET_TRUE (1) if quotes are incorrect, RET_FALSE (0) otherwise.
* Incorrect is defined as quotes opening but not ending.
* Opening quotes of a type (between simple and double)
* has the effect of not interpreting quotes of the other type
* until the first type closes.
*/
int	check_incorrect_quotes(char *input)
{
	t_quote	*quote;
	int		i;
	int		ret_val;

	quote = quote_init();
	i = 0;
	ret_val = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			ret_val |= check_simple(quote, i);
		else if (input[i] == '"')
			ret_val |= check_double(quote, i);
		if (ret_val)
			break ;
		++i;
	}
	ret_val |= quote->s_count % 2 != 0;
	ret_val |= quote->d_count % 2 != 0;
	free(quote);
	return (ret_val);
}
