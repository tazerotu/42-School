/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/03/11 12:27:13 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_pipe *pipe;
	pipe = malloc(sizeof(t_pipe));
    system("clear");
	// pipe = init(pipe, input, envp);	
	pipe = init_env(pipe, envp);
	free_all(pipe);
	return(0);
}

// bi_pwd();
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
	bi_echo(pipe->cmd);
*/
/* TEST Export, Unset
//	char *export[] = {"export", "TEST1=1", "TEST2=2", "TEST3=3", NULL};
// 	char *unset[] = {"unset", "TEST1", "TEST2", NULL};
// 	bi_export(pipe->envp, export);
// 	bi_env(pipe->envp);
// 	ft_printf("\n\n\n");
// 	bi_unset(pipe->envp, unset);
// 	bi_env(pipe->envp);
*/
/* TEST CD
// char *cd[] = {"cd", "/home/clai-ton/42-School", NULL};
// bi_cd(pipe->envp, cd);
// chdir("/home/ttas/42-School");
// printf("\n%s\n\n", getcwd(NULL, 0));
*/
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