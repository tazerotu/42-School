/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:09:31 by ttas              #+#    #+#             */
/*   Updated: 2024/06/25 16:21:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <limits.h>

# define FAILURE -1
# define SUCCESS 1
# define FD 100

/* ======= Structures ======= */
typedef struct s_stack
{
	int				items;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* ====== Sort ====== */
void				simple_sort(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **a, t_stack **b);
int					is_sorted_stack(t_stack **stack_a);

/* ======= Movements ======= */
// Push
int					push(t_stack **stack_to, t_stack **stack_from);

/**
 * Push from stack B to stack A
 */
void				pa(t_stack **stack_a, t_stack **stack_b);

/**
 * Push from stack A to stack B
 */
void				pb(t_stack **stack_a, t_stack **stack_b);

// Swap
int					swap(t_stack **stack_to);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

// Rotate
int					rotate(t_stack **stack_to);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

// Reverse Rotate
int					reverse_rotate(t_stack **stack_to);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

/* ======= Checker ======= */
int					checker(char **argv, int argc);
void				check_args(char **str);
int					is_sorted_str(char **str);

/* ======= Liste ======= */
void				*ft_lstnew(int items);
void				ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_lstlast(t_stack *stack);
void				ft_lstadd_front(t_stack **stack, t_stack *new);
int					ft_lstsize(t_stack *lst);

/* ======= Display ======= */
void				display(t_stack *stack_a, t_stack *stack_b);
int					error_message(int i);

/* ======= Utils ======= */
size_t				count_words(char *str, char c);
int					ft_atoi(char *nptr);
char				**ft_split(char *s, char c);
size_t				ft_strlen(char *s);
int					ft_strcmp(char *str1, char *str2);
void				ft_free(char **str);
void				free_split_array(char **split);
void				index_stack(t_stack **stack);

#endif