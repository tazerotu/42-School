/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:09:29 by ttas              #+#    #+#             */
/*   Updated: 2024/06/25 18:19:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	sort(t_stack **stack_a, t_stack **stack_b)
{
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
		ft_printf("Already Sorted\n");
		return (0);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		error_message(5);
	*stack_a = NULL;
	*stack_b = NULL;
	initstack(stack_a, argc, argv);
	if (sort(stack_a, stack_b) == SUCCESS)
		ft_printf("\e[0;32mOK\n\e[0;37m");
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
	// display(*stack_a, *stack_b);
