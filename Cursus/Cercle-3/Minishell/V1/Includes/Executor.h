/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:50 by ttas              #+#    #+#             */
/*   Updated: 2025/01/23 10:42:46 by ttas             ###   ########.fr       */
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

typedef struct s_command
{
	char **redir_tok;
	char **arg_tok;
}	t_cmd;

typedef struct s_pipe
{
	int semicolon;
	int n_pipe;
	char **envp;
	t_cmd *cmd;
}	t_pipe;

// Functions
	// Init
t_pipe init(t_pipe pipe, char *str, char **envp);
// t_splice *splicer(t_pipe pipe, char *str);

	// Command initialization
void verify_semicolon(void);
void verify_builtin(void);
void here_doc(void);
void split(void);

	// Execute
void execute(void);
void get_path(void);
void child_process(void);
void parent_process(void);
void redir(void);
		// Built-in
// with option -n
void bi_echo(char *str);
// with absolute or relative path
void bi_cd(char *path);
void bi_pwd(void);
void bi_export(void);
void bi_unset(void);
void bi_env(void);
void bi_exit(void);

#endif