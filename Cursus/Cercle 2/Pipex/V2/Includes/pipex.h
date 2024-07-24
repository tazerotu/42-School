#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

#define INVALID_INPUT 1

typedef struct s_ppx
{
	int input_fd;
	int output_fd;
	int here_doc;
	int cmd_count;
	char **cmd;

}	t_ppx;

void	execute(char *argv, char **envp);

// UTILS
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif