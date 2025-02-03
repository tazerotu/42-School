/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/02/03 10:02:57 by marvin           ###   ########.fr       */
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


	// bi_env(pipe, envp);
	// bi_pwd();
	// while(pipe->envp->next)
	// {
	// 	ft_printf("%s\n", pipe->envp->env);
	// 	pipe->envp = pipe->envp->next;
	// }



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