/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:04:55 by ttas              #+#    #+#             */
/*   Updated: 2024/06/24 09:09:11 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == SUCCESS)
		write(FD, "pa\n", 4);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == SUCCESS)
		write(FD, "pb\n", 4);
}
