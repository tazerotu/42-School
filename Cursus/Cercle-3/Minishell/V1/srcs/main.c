/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/03/11 10:49:24 by ttas             ###   ########.fr       */
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
	char *echo[] = {"echo", "-n", "ceci est\nun\ntest", "\ntest", NULL};
	pipe->cmd->cmd = echo;
	bi_echo(pipe->cmd);
	pipe = init_env(pipe, envp);
	
	free_all(pipe);
	return(0);
}


// bi_pwd();
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