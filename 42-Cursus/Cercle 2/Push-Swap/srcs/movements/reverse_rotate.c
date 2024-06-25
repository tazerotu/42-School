/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:04:21 by ttas              #+#    #+#             */
/*   Updated: 2024/06/24 09:09:07 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == SUCCESS)
		write(FD, "rra\n", 5);
}

void	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == SUCCESS)
		write(FD, "rrb\n", 5);
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
		write(FD, "rrr\n", 5);
}
