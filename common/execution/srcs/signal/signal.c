/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:28:17 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/26 14:21:57 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

/*

    ctrl + C redonne un prompt que la ligne soit vide ou pleine ou qu'on soit dans une commande bloquante comme cat
    ctrl + D exit si la ligne est vide et redonne un prompt dans un commande bloquante comme grep ""
    ctrl + \ ne fait rien sauf dans une commande bloquante, il permet de kill le process avec un message d'erreur.

	Check https://github.com/DimitriDaSilva/42_minishell/blob/master/README.md#exit-without-any-options
*/

int	g_sig_status;

void	handle_sigint(int signum)
{
	g_sig_status = 128 + signum;
	printf("^C\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int signum)
{
	g_sig_status = 128 + signum;
	printf("\\Quit\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	init_signal(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	g_sig_status = 0;
	sa_int.sa_sigaction = handle_sigint;
	sa_int.sa_flags = SA_RESTART | SA_NODEFER;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_sigaction = handle_sigquit;
	sa_quit.sa_flags = SA_RESTART | SA_NODEFER;
	sigemptyset(&sa_quit.sa_mask);
	sigaction(SIGQUIT, &sa_quit, NULL);
}

void	change_parent_signal(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_handler = SIG_IGN;
	sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa_int, NULL);
	sigaction(SIGQUIT, &sa_quit, NULL);
}