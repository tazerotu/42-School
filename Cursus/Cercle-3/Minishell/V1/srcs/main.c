/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/04/25 14:03:17 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

// Others
/* TEST get_env
	char **env = get_env(pipe->envp);
	int i = -1;
	printf("\n\n");
	while(env[++i])
		ft_printf("\n%s", env[i]);
	free_env(env);
*/

// Pipex
/*	TEST Heredoc
char *heredoc = here_doc("delimiteur");
ft_printf("\n%s", heredoc);
free(heredoc); 
*/

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
/*
static void test_export(t_pipe *pipe)
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
// while ( i < 10 )
// {
//     input = readline("\033[0;32mMinishell>\033[0m");
//     add_history(input);
	// printf("%i\n\n", pipe.n_pipe);
	// j = 0;
	// while(j < pipe.n_pipe)
	// {
	// 	printf("cmd : %s\n", pipe.cmd[j]);
	// 	printf("len : %zu\n\n", ft_strlen(pipe.cmd[j]));
	// 	j++;
	// }
	// i++;
// }
*/

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_pipe *pipe;
    system("clear");
	pipe = malloc(sizeof(t_pipe));
	init(pipe, envp);
	
	
	// char *str = get_env(pipe->envp, "USER");
	// ft_printf("\nUSER = %s\n\n", str);
	char *exp = expander("USEr : $USEr \n9USER : $9USER \nUSERt : $USERt \nUSER : $USER \n? : $? \n", pipe->envp, pipe);
	ft_printf("%s", exp);
	free(exp);
	// here_doc(pipe, "delimiteur");
	// int fd = open("./srcs/pipex/pipex_utils/.heredoc.tmp", O_RDONLY);
	// ft_printf("\n");
	// char *buffer = get_next_line(fd);
	// while(buffer)
	// {
	// 	ft_printf("%s", buffer);
	// 	free(buffer);
	// 	buffer = get_next_line(fd);
	// }
	// close(fd);
	free_pipe_env(pipe);
	return(0);
}

