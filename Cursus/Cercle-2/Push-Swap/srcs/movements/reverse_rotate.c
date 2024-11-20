/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:04:21 by ttas              #+#    #+#             */
/*   Updated: 2024/06/26 11:47:08 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// void	rra(t_stack **stack_a)
// {
// 	t_stack	*current;
// 	t_stack	*last;

// 	current = *stack_a;
// 	while (current->next->next)
// 		current = current->next;
// 	last = current->next;
// 	current->next = NULL;
// 	last->next = *stack_a;
// 	*stack_a = last;
// 	write(1, "rra\n", 4);
// }

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == SUCCESS)
		write(FD, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == SUCCESS)
		write(FD, "rrb\n", 4);
}

static int	rrab(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (reverse_rotate(stack_a) == SUCCESS)
		i = 1;
	else
		i = -1;
	if (reverse_rotate(stack_b) == SUCCESS)
		i = 1;
	else
		i = -1;
	return (i);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (rrab(stack_a, stack_b) == SUCCESS)
		write(FD, "rrr\n", 4);
}
