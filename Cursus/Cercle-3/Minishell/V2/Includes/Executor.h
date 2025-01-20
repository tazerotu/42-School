/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:50 by ttas              #+#    #+#             */
/*   Updated: 2025/01/20 13:18:21 by ttas             ###   ########.fr       */
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
typedef struct s_splice
{
	int length;
	char *str;
}	t_splice;

typedef struct s_pipe
{
	int input;
	int here_doc;
	int output;
	int err_output;
	int n_pipe;
	char **cmd;
	char **envp;
}	t_pipe;

// Functions
t_pipe init(t_pipe pipe, char *str, char **envp);
// t_splice *splicer(t_pipe pipe, char *str);
void here_doc(void);
void execute(void);
void get_path(void);
void child_process(void);
void parent_process(void);


#endif