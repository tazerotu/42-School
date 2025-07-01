/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:12:39 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/18 18:44:31 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_dblstsize(t_dblst *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->prev)
	{
		++i;
		lst = lst->prev;
	}
	while (lst->next)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}
