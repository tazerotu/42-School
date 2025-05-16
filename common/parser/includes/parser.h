/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:47 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/16 11:37:59 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../execution/includes/executor.h"
# include <stdio.h>
# include <stdlib.h>

# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

// ERROR HANDLING
// # define ERROR_FD 101
// # define ERROR_DIR 111
// # define ERROR_PWD 121
// # define ERROR_ENV 131

# define RET_NOTHING_DONE 100
# define RET_PROCESSED 101
# define RET_MALLOC_ERR 102
# define RET_SYNTAX_ERR 103
# define RET_TRUE 1
# define RET_FALSE 0

//////BY TTAS

// typedef struct s_env
// {
// 	char			*env;
// 	struct s_env	*previous;
// 	struct s_env	*next;
// }	t_env;

// typedef struct s_expander
// {
// 	char	*ret;
// 	char	*var;
// 	char	*tmp;
// 	int		start;
// 	int		end;
// 	int		dollar;
// }	t_expander;

// typedef struct s_pipe
// {
// 	int				exit;
// 	int				exit_status;
// 	int				n_pipe;
// 	int				fd_in;
// 	int				fd_out;
// 	char			*heredoc;
// 	char			**env;
// 	struct s_env	*envp;
// 	struct s_cmd	*cmd;
// }	t_pipe;

//////

enum e_token_quote_type
{
	Q_NONE,
	Q_SIMPLE,
	Q_DOUBLE
};

// typedef struct s_command
// {
// 	char				**redir_tok;
// 	char				**arg_tok;
// 	struct s_command	*next;
// }	t_cmd;

typedef struct s_quote_checker
{
	int	s_count;
	int	d_count;
	int	last_s;
	int	last_d;
}	t_quote;

void	free_words_dblst(t_dblst **words);
void	free_redir_early(t_cmd *cmd, int redir_count);
void	free_cmds(t_cmd *cmds);

int		error_message(int error, char *str);

int		check_incorrect_quotes(char *input);
t_cmd	*process_line(char *input, t_env *envp, t_pipe *pipe);
int		split_input(char *input, t_dblst **ret_dblst);
int		split_nonquote_space(char *input, t_dblst *tok_dblst);
int		split_special_char(t_dblst **tok_dblst);
int		split_input(char *input, t_dblst **ret_dblst);

int		insert_node_before(t_dblst *cur, char *substr);
size_t	count_occurences(char *str, int i);
int		check_first_or_last_is_pipe(t_dblst **words);

int		word_is_heredoc(char *word);
int		word_is_pipe(char *word);
int		word_is_redirection(char *word);
int		word_is_special(char *word);
int		check_invalid_follow_up(t_dblst **words);

int		create_cmd_list(t_dblst **words, t_cmd **cmds);
int		fill_cmds(t_dblst **words, t_cmd *cmds);

int		count_split_quotes(char *str);
unsigned int		skip_past_quote_end(char *str, int i, char quote);
void	expand_tok_rm_quote(t_cmd *cmd, t_env *envp, t_pipe *pipe);
/////////////BY TTAS

// // Functions
// 	// Init
// t_pipe	*init(t_pipe *pipe, char **envp);
// t_pipe	*init_env(t_pipe *pipe, char **envp);

// 	// Free
// void	free_pipe_env(t_pipe *pipe);
// void	free_env(char **env);

// 	// Command initialization
// void	verify_builtin(t_pipe *pipe);
// void	launch_builtin(t_pipe *pipe);
// void	here_doc(t_pipe *pipe, char *delimiter);

// 	// Execute
// void	execute(void);
// void	get_path(void);
// void	child_process(void);
// void	parent_process(void);
// void	set_redirection(t_pipe *pipe, char **redir);

// 	// Execute Utils
// char	**get_env_char(t_env *envp);
// char	*get_env(t_env *envp, char *str);
// char	*expander(char *str, t_env *envp, t_pipe *pipe);
// char	*verify_syntax(char *str, t_expander *expander);

// 	// Utils
// void	env_add_back(t_env *envp, t_env *new);
// void	env_delone(t_env *envp);
// t_env	*env_new(char *content);
// t_env	*env_last(t_env *env);
// int		env_size(t_env *env);
// int		variable_pos(t_env *envp, char *str);
// t_env	*find_env_pos(t_env *env, int pos);

///////////
#endif