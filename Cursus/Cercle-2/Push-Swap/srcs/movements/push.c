/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:04:55 by ttas              #+#    #+#             */
/*   Updated: 2024/06/26 11:46:54 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// void	pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*temp;

// 	if (ft_lstsize(*stack_a) < 1)
// 		return ;
// 	temp = *stack_a;
// 	*stack_a = (*stack_a)->next;
// 	temp->next = *stack_b;
// 	*stack_b = temp;
// 	write(1, "pb\n", 3);
// }

// void	pa(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*temp;

// 	if (ft_lstsize(*stack_b) < 1)
// 		return ;
// 	temp = *stack_b;
// 	*stack_b = (*stack_b)->next;
// 	temp->next = *stack_a;
// 	*stack_a = temp;
// 	write(1, "pa\n", 3);
// }

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == SUCCESS)
		write(FD, "pb\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == SUCCESS)
		write(FD, "pa\n", 3);
}
