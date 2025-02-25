/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/02/25 11:26:48 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Executor.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_pipe *pipe;
	// t_env **prev;
	pipe = malloc(sizeof(t_pipe));
    system("clear");
	// pipe = init(pipe, input, envp);
	pipe = init_env(pipe, envp);

	// char *unset[] = {"unset", "TEST1", "TEST2", "TEST3", NULL};
	bi_env(pipe->envp);
	// bi_unset(pipe->envp, unset);
	// ft_printf("\n\n\n");
	// bi_env(pipe->envp);
	// pipe->envp = env_last(pipe->envp);
	// while (pipe->envp)
	// {
	// 	prev = pipe->envp->previous;
	// 	free(pipe->envp->env);
	// 	free(pipe->envp);
	// 	pipe->envp = prev;
	// }
	free(pipe);
	return(0);
}



// bi_pwd();

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