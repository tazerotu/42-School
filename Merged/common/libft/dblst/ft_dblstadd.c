/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:26 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/14 18:21:24 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
* Adds the double-linked list node "new" at the first position
* of the double-linked list that "list" is part of.
* If "list" or "new" are NULL, nothing is done.
*/
void	ft_dblstadd_front(t_dblst *list, t_dblst *new)
{
	t_dblst	*next;

	if (!new || !list)
		return ;
	next = ft_dblstfirst(list);
	next->prev = new;
	new->next = next;
}

/*
* Adds the double-linked list node "new" at the last position
* of the double-linked list that "list" is part of.
* If "list" or "new" are NULL, nothing is done.
*/
void	ft_dblstadd_back(t_dblst *list, t_dblst *new)
{
	t_dblst	*prev;

	if (!new || !list)
		return ;
	prev = ft_dblstlast(list);
	prev->next = new;
	new->prev = prev;
}
