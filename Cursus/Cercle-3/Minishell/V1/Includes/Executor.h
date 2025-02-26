/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:50 by ttas              #+#    #+#             */
/*   Updated: 2025/02/26 15:26:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// Includes
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

// ERROR HANDLING
#define ERROR_FD 1001

// Struct
typedef struct s_env
{
	char *env;
	struct s_env *previous;
	struct s_env *next;
}	t_env;

typedef struct s_cmd
{
	char **redir;
	char **cmd;
	struct s_cmd *next;
}	t_cmd;

typedef struct s_pipe
{
	int semicolon;
	int n_pipe;
	struct s_env **envp;
	t_cmd *cmd;
	bool exit;
}	t_pipe;

// Functions
	// Init
t_pipe *init(t_pipe *pipe, char *str, char **envp);
t_pipe *init_env(t_pipe *pipe, char **envp);

	// Free
void free_pipe(t_pipe *pipe);

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

	//	Built-in
//	with option -n
void bi_echo(char *str);

//	with absolute or relative path
void bi_cd(char *path);

void bi_pwd(void);
void bi_export(void);
void bi_unset(t_env **envp, char **str);
void bi_env(t_env **envp);
void bi_exit(void);

		// Utils
void env_add_back(t_env **envp, t_env *new);
void env_delone(t_env *envp);
void	*env_new(char *content);
t_env *env_last(t_env *env);
int env_size(t_env *env);

#endif