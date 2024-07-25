#include "./Includes/Pipex.h"

void ft_init_pipex(int argc, char **argv, t_ppx pipex)
{
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.cmd_count = argc - 3 - pipex.here_doc;
}

void	child_proccess(char *cmd, char **envp, int inputfd)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (inputfd == STDIN)
			exit(1);
		else
			execute(cmd, envp);
	}
}

int main(int argc, char **argv, char **envp)
{
	t_ppx Pipex;
	int i;
	i = 0;

	if (argc < args_in(argv[1], &pipex))
		return (error(INVALID_INPUT));
	ft_init_pipex(argc, argv, &Pipex);
	dup2(pipex->input_fd, STDIN);
	dup2(pipex->output_fd, STDOUT);
	child_proccess(av[2], envp, pipex->input_fd);
	while (Pipex->cmd[i])
	{
		child_proccess(Pipex->cmd[i], envp, 1);
		i++;
	}
	child_proccess(av[2], env, pipex->input_fd);
	ft_cleanup(&Pipex);
	return 0;
}
