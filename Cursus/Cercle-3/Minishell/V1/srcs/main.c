/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/03/05 12:02:26 by marvin           ###   ########.fr       */
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
	chdir("/home/ttas/42-School");
	printf("%s\n", getcwd(NULL, 0));
	free_all(pipe);
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