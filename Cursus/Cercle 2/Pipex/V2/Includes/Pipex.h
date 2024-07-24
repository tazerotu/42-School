#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_ppx
{
	int input_fd;
	int output_fd;
	int here_doc = 0;
	int is_invalid_infile;
	char **cmd_args;
	int cmd_count;
}	t_ppx;

#endif