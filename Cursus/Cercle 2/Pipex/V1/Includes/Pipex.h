#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	error(void);
char	*find_path(char *cmd, char **envp);
int		get_next_line(char **line);
void	execute(char *argv, char **envp);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strnstr(char *big, char *little, size_t len);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif