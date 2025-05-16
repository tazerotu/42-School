/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:19:16 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/28 11:28:39 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	insert_node_before(t_dblst *cur, char *substr)
{
	ft_dblstinsert_before(cur, ft_dblstnew(substr));
	if (!cur->prev)
		return (RET_MALLOC_ERR);
	return (RET_PROCESSED);
}

size_t	count_occurences(char *str, int i)
{
	size_t	occ;

	occ = 1;
	while (str[i + occ] == str[i])
		++occ;
	return (occ);
}
