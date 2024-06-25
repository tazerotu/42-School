/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:49:28 by ttas              #+#    #+#             */
/*   Updated: 2024/06/25 19:30:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (FAILURE);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (SUCCESS);
}

int	swap(t_stack **stack_to)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_lstsize(*stack_to) < 2)
		return (FAILURE);
	first = *stack_to;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_to = second;
	return (SUCCESS);
}

int	rotate(t_stack **stack_to)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_to || !(*stack_to) || ft_lstsize(*stack_to) < 2)
		return (FAILURE);
	first = *stack_to;
	*stack_to = first->next;
	first->next = NULL;
	last = *stack_to;
	while (last->next)
		last = last->next;
	last->next = first;
	return (SUCCESS);
}

int	reverse_rotate(t_stack **stack_to)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_to || !(*stack_to) || ft_lstsize(*stack_to) < 2)
		return (FAILURE);
	first = *stack_to;
	last = NULL;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	if (last)
		last->next = NULL;
	first->next = *stack_to;
	*stack_to = first;
	return (SUCCESS);
}
