/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:41:52 by ttas              #+#    #+#             */
/*   Updated: 2024/10/14 15:40:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define INVALID_INPUT -1
# define INVALID_PATH -2
# define EXECUTE_ERROR -3
# define HERE_DOC_ERROR -4
# define STDIN 0
# define STDOUT 1

typedef struct s_ppx
{
	int		input_fd;
	int		output_fd;
	int		here_doc;
	int		cmd_count;
	char	**cmd;

}			t_ppx;

void		execute(char *argv, char **envp);
void		get_input_fd(char **argv, t_ppx *pipex);
void		get_output_fd(char *argv, t_ppx *pipex);
int			args_in(char *arg, t_ppx *pipex);
void		here_doc(char *argv, t_ppx *pipex);
void		error(int error);

// UTILS
char		**ft_split(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s);
char		*ft_strnstr(char *big, char *little, size_t len);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*get_next_line(int fd);

#endif