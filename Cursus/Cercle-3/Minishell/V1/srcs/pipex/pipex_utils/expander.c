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

// char	*expand(char *str, t_env *envp)
// {
// 	char	*ret;
// 	char	*tmp;
// 	char	*var;
// 	char	*value;
// }

// char	*dollar(char *str)
// {
// 	reutrn (NULL);
// }

char	*extract_variable(char *str, int *start, int *end)
{
	char	*var;

	*end = *start;
	while (str[*end] && str[*end] != ' ')
		(*end)++;
	var = ft_substr(str, *start, *end - *start);
	*start = *end;
	return (var);
}

char	*replace_variable(char *ret, char *var, t_env *envp)
{
	char	*value;
	char	*tmp;

	value = get_env(envp, var);
	tmp = ft_strjoin(ret, value);
	free(var);
	free(value);
	free(ret);
	ret = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (ret);
}

char	*expander(char *str, t_env *envp)
{
	char	*ret;
	char	*tmp;
	char	*var;
	int		start;
	int		end;

	ret = NULL;
	start = 0;
	end = 0;
	while (str[start])
	{
		if (str[start++] == '$')
		{
			ret = malloc(sizeof(char) * (start + 1));
			ft_strlcpy(ret, str, start);
			var = extract_variable(str, &start, &end);
			if (var)
				ret = replace_variable(ret, var, envp);
		}
	}
	tmp = ft_strjoin(ret, str + end);
	free(ret);
	return (tmp);
}



/*
char	*ret;
	int		start;
	int		end;
	char	*tmp;

	start = 0;
	tmp = NULL;
	while(str[start])
	{
		if(str[start++] == '$')
		{
			end = start;
			ret = malloc(sizeof(char) * (start + 1));
			ft_strlcpy(ret, str, start);
			while (str[end] && str[end] != ' ')
				end++;
			if (end > start)
			{
				char *var = ft_substr(str, start, end - start);
				char *value = get_env(envp, var);
				free(var);
				tmp = ft_strjoin(ret, value);
				free(value);
				free(ret);
				ret = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
				if(!ret)
					return (NULL);
				ft_strlcpy(ret, tmp, ft_strlen(tmp) + 1);
				free(tmp);
			}
			start = end;
		}
		start++;
	}
	str += end;
	tmp = ft_strjoin(ret, str);
	free(ret);
	ret = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if(!ret)
		return (NULL);
	ft_strlcpy(ret, tmp, ft_strlen(tmp) + 2);
	free(tmp);
	return(ret);
*/