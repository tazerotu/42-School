/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/05/16 11:23:15 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

// Others
//test_expander(pipe);
/*static void test_expander(t_pipe *pipe)
{
	char *str = {"USEr : $USEr \n9USER : $9USER \nUSERt : $USERt \nUSER9 : $USER9 \nUSER : $USER \n'USER' : '$USER'\n? : $? \n"};
	char *exp = expander(str, pipe->envp, pipe);
	ft_printf("%s", exp);
	free(exp);
}*/

// Pipex
//test_pipex(pipe);
/*static void test_pipex(t_pipe *pipe)
{
	t_cmd *cmd1;
	t_cmd *cmd2;
	t_cmd *cmd3;

	cmd3 = malloc(sizeof(t_cmd));
	cmd3->redir = NULL;
	cmd3->cmd = malloc(sizeof(char *) * 3);
	cmd3->cmd[0] = "wc";
	cmd3->cmd[1] = "-l";
	cmd3->cmd[2] = NULL;
	cmd3->next = NULL;

	cmd2 = malloc(sizeof(t_cmd));
	cmd2->redir = NULL;
	cmd2->cmd = malloc(sizeof(char *) * 3);
	cmd2->cmd[0] = "grep";
	cmd2->cmd[1] = "test";
	cmd2->cmd[2] = NULL;
	cmd2->next = cmd3;

	cmd1 = malloc(sizeof(t_cmd));
	cmd1->redir = NULL;
	// cmd1->redir = malloc(sizeof(char *) * 3);
	// cmd1->redir[0] = "<<";
	// cmd1->redir[1] = "delimiteur";
	// cmd1->redir[2] = NULL;
	cmd1->cmd = malloc(sizeof(char *) * 2);
	cmd1->cmd[0] = "env";
	cmd1->cmd[1] = NULL;
	cmd1->next = cmd2;
	// pipe->cmd = malloc(sizeof(t_cmd));
	// pipe->cmd->redir = NULL;
	// // pipe->cmd->redir = malloc(sizeof(char *) * 3);
	// // pipe->cmd->redir[0] = "<<";
	// // pipe->cmd->redir[1] = "test";
	// // pipe->cmd->redir[2] = NULL;
	// pipe->cmd->cmd = malloc(sizeof(char *) * 2);
	// pipe->cmd->cmd[0] = "cat";
	// pipe->cmd->cmd[1] = NULL;
	// // pipe->cmd->next = NULL;
	// // pipe->cmd->cmd[1] = "./srcs/main.c";
	// pipe->cmd->next = malloc(sizeof(t_cmd));
	// pipe->cmd->next->redir = NULL;
	// pipe->cmd->next->cmd = malloc(sizeof(char *) * 3);
	// pipe->cmd->next->cmd[0] = "grep";
	// pipe->cmd->next->cmd[1] = "test";
	// pipe->cmd->next->cmd[2] = NULL;
	// pipe->cmd->next->next = NULL;
	// pipe->cmd->next->next = malloc(sizeof(t_cmd));
	// pipe->cmd->next->next->redir = NULL;
	// pipe->cmd->next->next->cmd = malloc(sizeof(char *) * 3);
	// pipe->cmd->next->next->cmd[0] = "wc";
	// pipe->cmd->next->next->cmd[1] = "-l";
	// pipe->cmd->next->next->cmd[2] = NULL;
	// pipe->cmd->next->next->next = NULL;
	pipe->cmd = cmd1;
	pipex(pipe);
}*/

//test_heredoc(pipe);
/*static void test_heredoc(t_pipe *pipe)
{
	here_doc(pipe, "delimiteur");
	int fd = open("./srcs/pipex/pipex_utils/.heredoc.tmp", O_RDONLY);
	ft_printf("\n");
	char *buffer = get_next_line(fd);
	while(buffer)
	{
		ft_printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}*/

// Built-in
/* TEST Echo
	pipe->cmd = malloc(sizeof(t_cmd));
	pipe->cmd->redir = NULL;
	pipe->cmd->cmd = malloc(sizeof(char *) * 5);
	pipe->cmd->cmd[0] = malloc(5);
	pipe->cmd->cmd[1] = malloc(3);
	pipe->cmd->cmd[2] = malloc(17);
	pipe->cmd->cmd[3] = malloc(6);
	pipe->cmd->cmd[0] = "echo";
	pipe->cmd->cmd[1] = "aaa";
	pipe->cmd->cmd[2] = "ceci est un test";
	pipe->cmd->cmd[3] = "test";
	pipe->cmd->cmd[4] = NULL;
	bi_echo(pipe->cmd->cmd);
*/

/* TEST Echo + redir
	pipe->cmd = malloc(sizeof(t_cmd));
	pipe->cmd->redir = malloc(sizeof(char *) * 9);
	pipe->cmd->redir[0] = malloc(2);
	pipe->cmd->redir[1] = malloc(9);
	pipe->cmd->redir[2] = malloc(1);
	pipe->cmd->redir[3] = malloc(9);
	pipe->cmd->redir[4] = malloc(1);
	pipe->cmd->redir[5] = malloc(9);
	pipe->cmd->redir[6] = malloc(2);
	pipe->cmd->redir[7] = malloc(9);
	pipe->cmd->redir[0] = ">>";
	pipe->cmd->redir[1] = "1test.txt";
	pipe->cmd->redir[2] = ">";
	pipe->cmd->redir[3] = "2test.txt";
	pipe->cmd->redir[4] = ">";
	pipe->cmd->redir[5] = "3test.txt";
	pipe->cmd->redir[6] = ">>";
	pipe->cmd->redir[7] = "4test.txt";
	pipe->cmd->redir[8] = NULL;
	pipe->cmd->cmd = malloc(sizeof(char *) * 5);
	pipe->cmd->cmd[0] = malloc(5);
	pipe->cmd->cmd[1] = malloc(3);
	pipe->cmd->cmd[2] = malloc(17);
	pipe->cmd->cmd[3] = malloc(6);
	pipe->cmd->cmd[0] = "echo";
	pipe->cmd->cmd[1] = "aaa";
	pipe->cmd->cmd[2] = "ceci est un test";
	pipe->cmd->cmd[3] = "test";
	pipe->cmd->cmd[4] = NULL;
	bi_echo(pipe->cmd->cmd);
*/

// TEST Export, Unset
//test_export(pipe);
/*static void test_export(t_pipe *pipe)
{
	char *export[] = {"export", "TEST1=1", "TEST2=2", "TEST3=3", NULL};
	char *unset[] = {"unset", "TEST1", "TEST2", NULL};
	bi_export(pipe, pipe->envp, export);
	bi_env(pipe->envp, pipe);
	ft_printf("\n\n\n");
	bi_unset(pipe->envp, unset, pipe);
	bi_env(pipe->envp,pipe);
}*/

/* TEST CD
// char *cd[] = {"cd", "/home/clai-ton/42-School", NULL};
// bi_cd(pipe->envp, cd);
// chdir("/home/ttas/42-School");
// printf("\n%s\n\n", getcwd(NULL, 0));
*/

// Main
/* Readline
	int i = 0;
	char *input;
	while ( i < 10 )
{
    input = readline("\033[0;32mMinishell>\033[0m");
    add_history(input);
	ft_printf("%s\n", input);
	free(input);
	i++;
}
*/

// test_heredoc(pipe);
// int main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
//     system("clear");
// 	t_pipe *pipe;
// 	pipe = malloc(sizeof(t_pipe));
// 	init(pipe, envp);
// 	test_expander(pipe);
// 	// test_pipex(pipe);
// 	free_pipe_env(pipe);
// 	return(0);
// }

