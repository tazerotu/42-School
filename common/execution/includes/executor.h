/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:50 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 10:36:14 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// Includes
# include "../../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define STDIN 0
# define STDOUT 1

# define CMD_NOT_FOUND 127
# define INVALID_CMD 126

// ERROR HANDLING
# define ERROR_FD 1101
# define ERROR_DIR 1111
# define ERROR_PWD 1121
# define ERROR_ENV 1131

// Struct
typedef struct s_expander
{
	char	*ret;
	char	*var;
	char	*tmp;
	int		start;
	int		end;
	int		dollar;
}	t_expander;

typedef struct s_env
{
	char			*env;
	struct s_env	*previous;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char				**redir_tok;
	char				**arg_tok;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipe
{
	int				exit;
	int				exit_status;
	int				n_pipe;
	int				fd_in;
	int				fd_out;
	int				pipe_fd[2];
	pid_t			pid;
	char			*heredoc;
	char			**env;
	struct s_env	*envp;
	struct s_cmd	*cmd;
}	t_pipe;

// Functions
	// Init
t_pipe	*init(t_pipe *pipe, char **envp);
t_pipe	*init_env(t_pipe *pipe, char **envp);

	// Free
void	free_pipe_env(t_pipe *pipe);
void	free_env(char **env);
void	ft_free_cmd(t_cmd *cmd);

	// Command initialization
int		verify_builtin1(t_pipe *pipe);
int 	verify_builtin2(t_cmd *cmd);
void	launch_builtin(t_pipe *pipe);
void	here_doc(t_pipe *pipe, char *delimiter);

	// Execute
// char	*get_path(char *cmd, char **envp);
void	set_redirection(t_pipe *pipe, char **redir);
void	pipex(t_pipe *pipex);
void	execute_cmd(t_pipe *pipex);

	// Execute Utils
char	**get_env_char(t_env *envp);
char	*get_env(t_env *envp, char *str);
char	*expander(char *str, t_env *envp, t_pipe *pipe);
char	*verify_syntax(char *str, t_expander *expander);
void	ft_close(int fd);
void	child_process(t_pipe *pipex, int prev_fd, int *pipe_fd);
void	parent_cleanup(int *prev_fd, int *pipe_fd);

	//	Built-in
//	with option -n
void	bi_echo(char **str, t_pipe *pipe);

//	with absolute or relative path
void	bi_cd(t_env *env, char **path, t_pipe *pipe);

void	bi_pwd(t_pipe *pipe);
t_env	*bi_export(t_pipe *pipe, char **str);
void	bi_unset(char **str, t_pipe *pipe);
void	bi_env(t_env *envp, t_pipe *pipe);
int		bi_exit(t_pipe *pipe, char **cmd);

		// Utils
void	env_add_back(t_env *envp, t_env *new);
void	env_delone(t_env *envp);
t_env	*env_new(char *content);
t_env	*env_last(t_env *env);
int		env_size(t_env *env);
int		variable_pos(t_env *envp, char *str);
t_env	*find_env_pos(t_env *env, int pos);
int		error_message_exec(int error, char *str);

#endif