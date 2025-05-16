/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:15:33 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/17 19:31:55 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
* Deletes the node given from the double-linked list,
* linking the nodes before and after it together.
*/
void	ft_dblstdelone(t_dblst *node, void (*del)(void *))
{
	if (node)
	{
		if (node->next)
			node->next->prev = node->prev;
		if (node->prev)
			node->prev->next = node->next;
		del(node->content);
		free(node);
	}
}

/*
* Deletes the n nodes before the given node, said node not included.
* Links the two parts of the "cut" double list.
*/
void	ft_dblstdel_n_before(t_dblst *node, void (*del)(void *), size_t n)
{
	t_dblst	*a;
	t_dblst	*b;
	size_t	i;

	i = 0;
	a = node->prev;
	while (i < n && a)
	{
		b = a;
		a = a->prev;
		del(b->content);
		free(b);
		++i;
	}
	node->prev = a;
	a->next = node;
}

/*
* Deletes the n nodes after the given node, said node not included.
* Links the two parts of the "cut" double list.
*/
void	ft_dblstdel_n_after(t_dblst *node, void (*del)(void *), size_t n)
{
	t_dblst	*a;
	t_dblst	*b;
	size_t	i;

	i = 0;
	a = node->next;
	while (i < n && a)
	{
		b = a;
		a = a->next;
		del(b->content);
		free(b);
		++i;
	}
	node->next = a;
	a->prev = node;
}
