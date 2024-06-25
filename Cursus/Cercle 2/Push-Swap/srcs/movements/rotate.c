/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:04:57 by ttas              #+#    #+#             */
/*   Updated: 2024/06/24 09:08:59 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a) == SUCCESS)
		write(FD, "ra\n", 4);
}

void	rb(t_stack **stack_b)
{
	if (rotate(stack_b) == SUCCESS)
		write(FD, "rb\n", 4);
}

static int	r(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (rotate(stack_a) == SUCCESS)
		i = SUCCESS;
	else
		return (FAILURE);
	if (rotate(stack_b) == SUCCESS)
		i = SUCCESS;
	else
		return (FAILURE);
	return (i);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (r(stack_a, stack_b) == SUCCESS)
		write(FD, "rr\n", 4);
}
