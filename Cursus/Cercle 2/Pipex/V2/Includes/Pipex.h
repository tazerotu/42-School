/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/08/01 09:25:09 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:25:09 by ttas             ###   ########.fr       */
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

# define INVALID_INPUT 1
# define STDIN 0
# define STDOUT 1

typedef struct s_ppx
{
	int input_fd;
	int output_fd;
	int here_doc;
	int cmd_count;
	char **cmd;

} t_ppx;

void	execute(char *argv, char **envp);
void	get_input_fd(char **argv, t_ppx *pipex);
void	get_output_fd(char *argv, t_ppx *pipex);
int	args_in(char *arg, t_ppx *pipex);
void	here_doc(char *argv, t_ppx *pipex);

// UTILS
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif