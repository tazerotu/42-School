/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:44:39 by ttas              #+#    #+#             */
/*   Updated: 2025/05/26 09:51:35 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/executor.h"

static void	*str_swap(char **ret, int current, int checking)
{
	char	*tmp;

	tmp = ret[current];
	ret[current] = ret[checking];
	ret[checking] = tmp;
	return (ret);
}

t_env	*bubble_sort(t_env *envp)
{
	char	**ret;
	int		current;
	int		checking;

	ret = get_env_char(envp);
	current = 0;	
	while(ret[current])
	{
		checking = current;
		while(ret[checking])
		{
			if(ft_strncmp(ret[current], ret[checking], INT_MAX) > 0)
				str_swap(ret, current, checking);
			checking++;
		}
		current++;
	}
	current = -1;
	while(ret[++current])
		ft_printf("declare -x %s\n", ret[current]);
	free_env(ret);
	return (NULL);
}
