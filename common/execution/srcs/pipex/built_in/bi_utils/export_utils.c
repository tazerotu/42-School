/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:44:39 by ttas              #+#    #+#             */
/*   Updated: 2025/06/02 16:11:21 by marvin           ###   ########.fr       */
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

static void print_export(char *str)
{
	char *equal_sign;

	equal_sign = ft_strchr(str, '=');
	if (str)
	{
		ft_printf("declare -x ");
		if(equal_sign != NULL && *(equal_sign + 1) == '\0')
			ft_printf("%s''\n", str);
		else
			ft_printf("%s\n", str);
	}
}

t_env	*bubble_sort(t_env *envp)
{
	char	**ret;
	int		current;
	int		checking;

	ret = get_env_char(envp);
	current = 0;
	while (ret[current])
	{
		checking = current;
		while (ret[checking])
		{
			if (ft_strncmp(ret[current], ret[checking], INT_MAX) > 0)
				str_swap(ret, current, checking);
			checking++;
		}
		current++;
	}
	current = -1;
	while (ret[++current])
		print_export(ret[current]);
	free_env(ret);
	return (NULL);
}
