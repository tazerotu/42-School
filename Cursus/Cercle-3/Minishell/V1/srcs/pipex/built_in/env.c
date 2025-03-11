/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:54 by ttas              #+#    #+#             */
/*   Updated: 2025/03/11 10:40:32 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	bi_env(t_env *envp)
{
	t_env	*tmp;

	tmp = envp;
	while (tmp && tmp->next)
	{
		ft_printf("%s\n", tmp->env);
		tmp = tmp->next;
	}
	ft_printf("%s\n", tmp->env);
}
