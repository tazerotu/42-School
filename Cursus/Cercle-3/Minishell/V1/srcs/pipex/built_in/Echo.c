/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:56 by ttas              #+#    #+#             */
/*   Updated: 2025/03/11 11:06:21 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Verifies the number of arguments to see if it can print something
int echo_args(char **str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return(i);
}

// find the type of redirection and opens the file accordingly
int	print_redirection(char **redir)
{
	int	fd;
	
	fd = 0;
	if(ft_strnstr(redir[0], ">>", 2))
		fd = open(redir[1], O_RDWR | O_CREAT | O_APPEND, S_IWUSR);
	else if(ft_strnstr(redir[0], ">", 1))
		fd = open(redir[1], O_RDWR | O_CREAT | O_TRUNC, S_IWUSR);
	if(fd == -1)
	{
		error_message(ERROR_FD, NULL);
		return(-1);
	}
	return(fd);
}

// Prints the argument, ex: "ceci est un test"
void echo_print(t_cmd *cmd, char *str, bool option)
{
	int fd;
	if(cmd->redir)
		fd = print_redirection(cmd->redir);
	else 
		fd = 1;
	if(echo_args(str) == 1)
		ft_fprintf(fd, "\n", str);
	ft_fprintf(fd, "%s", str);
	if(!option)
		ft_fprintf(fd, "\n");
}

// The echo function, with only the -n option
void bi_echo(t_cmd *cmd)
{
	int args;
	int j;
	bool option;
	char **str;
	
	str = cmd->cmd;
	j = 1;
	option = false;
	args = echo_args(str);
	if(args == 1)
	{
		echo_print(cmd, str, false);
		return ;
	}
	if(ft_strnstr(str[j], "-n", 2))
	{
		option = true;
		j++;
	}
	while(str[j])
	{
		echo_print(cmd, str[j], option);
		j++;
	}
}