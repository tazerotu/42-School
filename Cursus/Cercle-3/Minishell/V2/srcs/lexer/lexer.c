/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:07:03 by clai-ton          #+#    #+#             */
/*   Updated: 2025/02/20 18:17:52 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

t_cmd	*process_line(char *input)
{
	t_list	**tok_lst;

	if (check_incorrect_quotes(input))
		return (NULL);
	tok_lst = ft_tokenize_1(input);
	trim_spaces(tok_lst);
	replace_var(tok_lst);
	//todo
	ft_lstclear(tok_lst, del_token_1);
	return (NULL);
}
