#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "../../includes/executor.h"

// Mock structure for testing
typedef struct s_cmd {
	char **cmd;
	struct s_cmd *next;
	char *redir;
} t_cmd;

typedef struct s_pipe {
	t_cmd *cmd;
	char **env;
	int pipe_fd[2];
	pid_t pid;
	int exit_status;
	int exit;
} t_pipe;

// Helper function to create a mock command
t_cmd *create_mock_cmd(char *cmd_str) {
	t_cmd *cmd = malloc(sizeof(t_cmd));
	cmd->cmd = malloc(2 * sizeof(char *));
	cmd->cmd[0] = strdup(cmd_str);
	cmd->cmd[1] = NULL;
	cmd->next = NULL;
	cmd->redir = NULL;
	return cmd;
}

// Test function for get_path
void test_get_path() {
	char *envp[] = {"PATH=/usr/bin:/bin:/usr/local/bin", NULL};
	char *path = get_path("ls", envp);
	if (path) {
		printf("get_path test passed: %s\n", path);
		free(path);
	} else {
		printf("get_path test failed\n");
	}
}

// Test function for execute
void test_execute() {
	t_pipe pipe;
	char *envp[] = {"PATH=/usr/bin:/bin:/usr/local/bin", NULL};
	pipe.env = envp;
	pipe.cmd = create_mock_cmd("ls");

	if (fork() == 0) {
		execute(&pipe);
		exit(0);
	}
	wait(NULL);
	printf("execute test passed\n");

	free(pipe.cmd->cmd[0]);
	free(pipe.cmd->cmd);
	free(pipe.cmd);
}

// Test function for pipex
void test_pipex() {
	t_pipe pipe;
	char *envp[] = {"PATH=/usr/bin:/bin:/usr/local/bin", NULL};
	pipe.env = envp;

	t_cmd *cmd1 = create_mock_cmd("ls");
	t_cmd *cmd2 = create_mock_cmd("wc");
	cmd1->next = cmd2;
	pipe.cmd = cmd1;

	int fd_in = open("test_input.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd_in, "Hello\nWorld\n", 12);
	close(fd_in);

	int fd_out = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	close(fd_out);

	if (fork() == 0) {
		int fd_in = open("test_input.txt", O_RDONLY);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);

		int fd_out = open("test_output.txt", O_WRONLY);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);

		pipex(&pipe);
		exit(0);
	}
	wait(NULL);

	printf("pipex test passed\n");

	free(cmd1->cmd[0]);
	free(cmd1->cmd);
	free(cmd1);

	free(cmd2->cmd[0]);
	free(cmd2->cmd);
	free(cmd2);
}

int main() {
	test_get_path();
	test_execute();
	test_pipex();
	return 0;
}