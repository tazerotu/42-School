/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:45:51 by ttas              #+#    #+#             */
/*   Updated: 2024/06/07 09:33:02 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_lstlast(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack)
		ft_lstlast(*stack)->next = new;
	else
		*stack = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	*ft_lstnew(int items)
{
	t_stack	*stack1;

	stack1 = malloc(sizeof(t_stack));
	if (!stack1)
		return (NULL);
	stack1->items = items;
	stack1->next = NULL;
	return (stack1);
}

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
