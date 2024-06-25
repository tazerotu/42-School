/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:44:45 by ttas              #+#    #+#             */
/*   Updated: 2024/06/24 09:47:31 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_message(int i)
{
	if (i == 0)
		write(2, "\e[0;31mError\e[0;97m\n", 20);
	if (i == 1)
		ft_printf("\e[0;31mError\e[0;97m, Too few arguments\n");
	if (i == 2)
		ft_printf("\e[0;31mError\e[0;97m, Non numerical arguments\n");
	if (i == 3)
		ft_printf("\e[0;31mError\e[0;97m, Duplicates found\n");
	if (i == 4)
		ft_printf("\e[0;31mError\e[0;97m, Int overflow\n");
	if (i == 5)
		ft_printf("\e[0;31mError\e[0;97m, Allocation failed\n");
	if (i == 6)
		ft_printf("\e[0;31mError\e[0;97m, Empty stack\n");
	if (i == 7)
		ft_printf("\e[0;31mError\e[0;97m, Move failed\n");
	exit(EXIT_FAILURE);
}

static void	display2(int i)
{
	if (i == 1)
	{
		ft_printf("\e[0;34m╔══════════ ");
		ft_printf("\e[0;94mTableau final");
		ft_printf("\e[0;34m ══════════╗\n\e[0;97m");
	}
	if (i == 2)
	{
		ft_printf("\e[0;34m╠═══════════════════════════════════╣\e[0;97m");
		ft_printf("\n\e[0;34m║\e[0;97m   Stack A\t|");
		ft_printf("     Stack B       \e[0;34m║\n");
		ft_printf("╚═══════════════════════════════════╝\n\e[0;97m");
	}
}

static void	display_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	num;

	while (stack_a || stack_b)
	{
		if (stack_a == NULL)
			ft_printf("-");
		else
		{
			num = stack_a->items;
			stack_a = stack_a->next;
			ft_printf(" %d", num);
		}
		if (num > 10000000 || num < -1000000)
			ft_printf("\t|\t");
		else
			ft_printf("\t\t|\t");
		if (stack_b == NULL)
			ft_printf("-\n");
		else
		{
			num = stack_b->items;
			ft_printf("%d\n", num);
			stack_b = stack_b->next;
		}
	}
}

void	display(t_stack *stack_a, t_stack *stack_b)
{
	display2(1);
	display_stack(stack_a, stack_b);
	display2(2);
}
