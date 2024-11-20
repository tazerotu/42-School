/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:41:52 by ttas              #+#    #+#             */
/*   Updated: 2024/10/15 08:49:25 by ttas             ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strchr(char *s, int c);
// void		*ft_memmove(void *dest, void *src, size_t n);
// void		*ft_memcpy(void *dest, void *src, size_t n);

#endif