/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:17:34 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/14 17:15:45 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dblstinsert_before(t_dblst *lst_node, t_dblst *new)
{
	t_dblst	*tmp;

	tmp = lst_node->prev;
	lst_node->prev = new;
	if (tmp)
		tmp->next = new;
	new->prev = tmp;
	new->next = lst_node;
}

void	ft_dblstinsert_after(t_dblst *lst_node, t_dblst *new)
{
	t_dblst	*tmp;

	tmp = lst_node->next;
	lst_node->next = new;
	if (tmp)
		tmp->prev = new;
	new->next = tmp;
	new->prev = lst_node;
}
