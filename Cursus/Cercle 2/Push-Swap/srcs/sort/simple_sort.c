/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:06:54 by ttas              #+#    #+#             */
/*   Updated: 2024/06/24 09:47:25 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort3(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack_a;
	second = (*stack_a)->next;
	third = second->next;
	if (first->items > second->items && second->items > third->items)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first->items > third->items && third->items > second->items)
		ra(stack_a);
	else if (second->items > first->items && first->items > third->items)
		rra(stack_a);
	else if (third->items > first->items && first->items > second->items)
		sa(stack_a);
	else if (second->items > third->items && third->items > first->items)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

static void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*smallest;

	tmp = *stack_a;
	smallest = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (smallest->items > tmp->items)
			smallest = tmp;
		tmp = tmp->next;
	}
	while ((*stack_a)->items != smallest->items)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*smallest;

	tmp = *stack_a;
	smallest = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (smallest->items > tmp->items)
			smallest = tmp;
		tmp = tmp->next;
	}
	while ((*stack_a)->items != smallest->items)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort5(stack_a, stack_b);
}
