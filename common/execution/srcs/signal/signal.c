/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:28:17 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/28 14:39:52 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

int	g_sig_status;

static void	sigaction_my_handler(int signum)
{
	g_sig_status = 128 + signum;
	if (signum == SIGQUIT)
		ignore_sig(SIGQUIT);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	basic_handle_sig(int signum)
{
	struct sigaction	sa;

	sa.sa_handler = sigaction_my_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(signum, &sa, NULL);
}

void	ignore_sig(int signum)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sigaction(signum, &sa, NULL);
}

void	init_sigintquit_handling(void)
{
	basic_handle_sig(SIGINT);
	ignore_sig(SIGQUIT);
}

void	init_sigintquit_ignore(void)
{
	ignore_sig(SIGINT);
	ignore_sig(SIGQUIT);
}
