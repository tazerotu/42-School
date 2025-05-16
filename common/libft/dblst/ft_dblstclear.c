/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:27:04 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/25 16:59:08 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Clears a double-linked list from the node preceding lst.
//lst becomes the new first node.
void	ft_dblstclear_before(t_dblst *lst, void (*del)(void *))
{
	t_dblst	*a;
	t_dblst	*b;

	a = lst->prev;
	while (a)
	{
		b = a;
		a = a->prev;
		del(b->content);
		free(b);
	}
	lst->prev = NULL;
}

//Clears a double-linked list from the node following lst.
//lst becomes the new last node.
void	ft_dblstclear_after(t_dblst *lst, void (*del)(void *))
{
	t_dblst	*a;
	t_dblst	*b;

	a = lst->next;
	while (a)
	{
		b = a;
		a = a->next;
		del(b->content);
		free(b);
	}
	lst->next = NULL;
}

//Clears a whole double-linked list
void	ft_dblstclear(t_dblst *lst, void (*del)(void *))
{
	if (!lst)
		return;
	ft_dblstclear_before(lst, del);
	ft_dblstclear_after(lst, del);
	ft_dblstdelone(lst, del);
}
