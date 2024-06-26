/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:09:29 by ttas              #+#    #+#             */
/*   Updated: 2024/06/26 10:45:19 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted_stack(stack_a) == SUCCESS)
		return (SUCCESS);
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
		radix_sort(stack_a, stack_b);
	return (is_sorted_stack(stack_a));
}

static void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(stack);
}

static void	initstack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (checker(argv, argc) == SUCCESS)
	{
		write(1, "Already Sorted\n", 15);
		return (0);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		error_message(5);
	*stack_a = NULL;
	*stack_b = NULL;
	initstack(stack_a, argc, argv);
	sort(stack_a, stack_b);
	// display(*stack_a, *stack_b);
	// if (is_sorted_stack(stack_a))
	// 	ft_printf("OK\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
