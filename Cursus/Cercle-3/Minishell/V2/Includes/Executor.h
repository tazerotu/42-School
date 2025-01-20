/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:50 by ttas              #+#    #+#             */
/*   Updated: 2025/01/20 11:24:28 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// Includes
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// Struct
typedef struct s_cmd
{
	char *cmd;
	char *args;
}	t_cmd;

typedef struct s_pipe
{
	int input;
	int output;
	int err_output;
	struct s_cmd cmd;
}	t_pipe;

typedef struct s_splice
{
	int length;
	char *str;
}	t_splice;

int tokenizer(char *input);
int quote(char *input, int start);

#endif