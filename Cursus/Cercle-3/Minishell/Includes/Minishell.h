/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:29:26 by ttas              #+#    #+#             */
/*   Updated: 2025/01/14 10:06:27 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Includes
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// Struct
typedef struct s_history
{
	int n;
	char *str;
	struct s_history *previous;
	struct s_history *next;
}	t_history;

typedef struct s_splice
{
	int length;
	char *str;
}	t_splice;

int tokenizer(char *input);
int quote(char *input, int start);

#endif