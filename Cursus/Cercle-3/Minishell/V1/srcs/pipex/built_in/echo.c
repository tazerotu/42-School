/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:56 by ttas              #+#    #+#             */
/*   Updated: 2025/03/20 12:16:56 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Verifies the number of arguments to see if it can print something
int	echo_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// find the type of redirection and opens the file accordingly
int	print_redirection(char **redir)
{
	int	fd;
	int	i;

	i = 0;
	fd = 1;
	if (!redir)
		return (fd);
	while (redir[i] && redir[i + 1])
	{
		if (fd)
		 close(fd);
		if (ft_strnstr(redir[i], ">>", 2))
			fd = open(redir[++i], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
		else if (ft_strnstr(redir[i], ">", 1))
			fd = open(redir[++i], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		i++;
	}
	if (fd == -1)
	{
		error_message(ERROR_FD, NULL);
		return (-1);
	}
	return (fd);
}

// Prints the argument, ex: "ceci est un test"
void	echo_print(t_cmd *cmd, char *str, bool option, int args)
{
	int	fd;

	if (cmd->redir)
		fd = print_redirection(cmd->redir);
	else
		fd = 1;
	if (args != 0)
		ft_fprintf(fd, "%s", str);
	if (option == false && args == 3)
		ft_fprintf(fd, "\n");
	if (fd != 1)
		close(fd);
}

// The echo function, with only the -n option
void	bi_echo(t_cmd *cmd)
{
	int		args;
	int		j;
	bool	option;
	char	**str;

	str = cmd->cmd;
	j = 1;
	option = false;
	args = echo_args(str);
	if (args == 1)
	{
		echo_print(cmd, str[1], false, 0);
		return ;
	}
	if (ft_strnstr(str[j++], "-n", 2))
		option = true;
	while (str[j])
	{
		echo_print(cmd, str[j++], option, args);
		args--;
		if(args > 2)
			ft_printf(" ");
	}
}
