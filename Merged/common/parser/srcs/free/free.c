/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:11 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/16 11:37:39 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	free_words_dblst(t_dblst **words)
{
	ft_dblstclear(*words, free);
	free (words);
	words = NULL;
}
/*
void ft_do_nothing(void * arg)
{
	(void) arg;
}
*/

// void	free_pipe_env(t_pipe *pipe)
// {
// 	t_env	*tmp;

// 	while (pipe->envp->previous)
// 		pipe->envp = pipe->envp->previous;
// 	while (pipe->envp)
// 	{
// 		tmp = pipe->envp->next;
// 		free(pipe->envp);
// 		pipe->envp = tmp;
// 	}
// 	free(pipe->envp);
// 	free(pipe);
// }

// void	free_env(char **env)
// {
// 	int	i;

// 	i = -1;
// 	while (env[++i])
// 		free(env[i]);
// 	free(env);
// }
