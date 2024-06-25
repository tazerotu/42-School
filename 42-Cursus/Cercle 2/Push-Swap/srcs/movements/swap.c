/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:05:03 by ttas              #+#    #+#             */
/*   Updated: 2024/06/24 09:08:54 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack **stack_a)
{
	if (swap(stack_a) == SUCCESS)
		write(FD, "sa\n", 4);
}

void	sb(t_stack **stack_b)
{
	if (swap(stack_b) == SUCCESS)
		write(FD, "sb\n", 4);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_b) == SUCCESS || swap(stack_a) == SUCCESS)
		write(FD, "ss\n", 4);
}
