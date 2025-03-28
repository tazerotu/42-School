/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:13:07 by marvin            #+#    #+#             */
/*   Updated: 2025/03/28 15:13:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

char	*expander(char *str, t_pipe *pipe)
{
	char	*ret;
	int		i;

	i = 0;
	

	ret[i] = '\0';
	return (ret);
}

char	*expand_one(char *str, t_pipe *pipe)
{
	while (str[i] != '$' && str[i++] != '\0')
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	ret = ft_strlcpy(ret, str, i);
}

char	*interogation(char *str, t_pipe *pipe)
{
	char	*ret;
	int		i;

	i = 0;

	ret[i] = '\0';
	return (ret);
}
