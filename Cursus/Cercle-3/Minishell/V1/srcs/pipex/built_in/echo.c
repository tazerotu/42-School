/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:56 by ttas              #+#    #+#             */
/*   Updated: 2025/03/24 15:51:22 by marvin           ###   ########.fr       */
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
	if(i >= 2)
		if(ft_strnstr(str[1], "-n", 2))
			i--;
	i--;
	return (i);
}

// Prints the argument, ex: "ceci est un test"
void	echo_print(char **str, int args, int i, bool option)
{
	while (str[i])
	{
		ft_printf("%s", str[i]);
		i++;
		args--;
		if(args > 0)
			ft_printf(" ");
	}
	if (option == false)
		ft_printf("\n");	
}

// The echo function, with only the -n option
void	bi_echo(char **str)
{
	int		i;
	int		args;
	bool 	option;

	i = 1;
	option = false;
	args = echo_args(str);
	if (str[1] && ft_strnstr(str[1], "-n", 2))
		option = true;
	if (option == true)
	i++;
	if (args == 0 && option == false)
	{
		ft_printf("\n");
		return ;
	}
	echo_print(str, args, i, option);
}

/*
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
*/

// find the type of redirection and opens the file accordingly
// int	print_redirection(char **redir)
// {
// 	int	fd;
// 	int	i;

// 	i = 0;
// 	fd = 1;
// 	if (!redir)
// 		return (fd);
// 	while (redir[i] && redir[i + 1])
// 	{
// 		if (fd)
// 		 close(fd);
// 		if (ft_strnstr(redir[i], ">>", 2))
// 			fd = open(redir[++i], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
// 		else if (ft_strnstr(redir[i], ">", 1))
// 			fd = open(redir[++i], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
// 		i++;
// 	}
// 	if (fd == -1)
// 	{
// 		error_message(ERROR_FD, NULL);
// 		return (-1);
// 	}
// 	return (fd);
// }