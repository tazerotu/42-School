/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/04/28 10:22:07 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

// Get the path of the command
// If the command is not found, return an error
char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(void);
void	child_process(void);
void	parent_process(void);

void	pipex(t_pipe *pipe)
{
	int	fd[2];

	while (pipe->cmd)
	{
		if (pipe(fd) == -1)
			return (ERROR_FD);
		if (pipe->env)
		{
			free_env(pipe->env);
			pipe->env = get_env_char(pipe->envp);
		}
		else
			pipe->env = get_env_char(pipe->envp);
		fd = set_redirection(pipe->cmd->redir);
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		if (verify_builtin(pipe) == 0)
			launch_builtin(pipe);
		else
			execute(void);
	}
	free_env(pipe->env);
}
