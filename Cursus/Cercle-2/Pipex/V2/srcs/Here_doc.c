/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:33:33 by ttas              #+#    #+#             */
/*   Updated: 2024/10/21 11:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Pipex.h"

int	args_in(char *arg, t_ppx *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

// void	here_doc(char *argv, t_ppx *pipex)
// {
// 	int file;
// 	char *buf;

// 	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
// 	if (file < 0)
// 		error(HERE_DOC_ERROR);
// 	while (1)
// 	{
// 		write(1, "heredoc> ", 9);
// 		if (get_next_line(0, &buf) < 0)
// 			exit(1);
// 		if (!ft_strncmp(argv, buf, ft_strlen(argv) + 1))
// 			break ;
// 		write(file, buf, ft_strlen(buf));
// 		write(file, "\n", 1);
// 		free(buf);
// 	}
// 	free(buf);
// 	close(file);
// 	pipex->input_fd = open(".heredoc_tmp", O_RDONLY);
// 	if (pipex->input_fd < 0)
// 	{
// 		unlink(".heredoc_tmp");
// 		error(HERE_DOC_ERROR);
// 	}
// }