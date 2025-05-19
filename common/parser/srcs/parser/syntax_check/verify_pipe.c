/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:17:13 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/19 12:58:22 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

int	check_first_or_last_is_pipe(t_dblst **words)
{
	char	*str;

	str = (char *) ft_dblstfirst(*words)->content;
	if (str[0] == '|')
		return (RET_TRUE);
	str = (char *) ft_dblstlast(*words)->content;
	if (str[0] == '|')
		return (RET_TRUE);
	return (RET_FALSE);
}
