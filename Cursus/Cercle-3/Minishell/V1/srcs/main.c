/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/02/12 18:08:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Executor.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_pipe *pipe;
	// char *input;
    // int i = 0;
	// int j = 0;
	pipe = malloc(sizeof(t_pipe));
    system("clear");
	// pipe = init(pipe, input, envp);
	pipe = init_env(pipe, envp);

	char *unset[] = {"unset", "TEST1", "TEST2", "TEST3", NULL};
	bi_env(pipe->envp);
	bi_unset(pipe->envp, unset);
	ft_printf("\n\n\n");
	bi_env(pipe->envp);
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
	free(pipe);
	return(0);
}