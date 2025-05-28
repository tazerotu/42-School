/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:47 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/28 14:40:46 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../execution/includes/executor.h"
# include <stdio.h>
# include <stdlib.h>

# define RET_NOTHING_DONE 100
# define RET_PROCESSED 101
# define RET_MALLOC_ERR 102
# define RET_SYNTAX_ERR 103
# define RET_TRUE 1
# define RET_FALSE 0

enum e_token_quote_type
{
	Q_NONE,
	Q_SIMPLE,
	Q_DOUBLE
};

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

int		error_parsing(int error, char *str);

int		check_incorrect_quotes(char *input);
t_cmd	*process_line(char *input, t_pipe *pipe);
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
int		rm_empty_quote_tok(char *tok);
int		skip_past_quote_end(char *str, int i, char quote);
void	expand_token2(char *str, t_pipe *pipe, char **tmp);
int		expand_tok_rm_quote(t_cmd *cmd, t_pipe *pipe);
char	*clean_expand(char *str);
int		is_special_dollar_char(char c);

#endif
