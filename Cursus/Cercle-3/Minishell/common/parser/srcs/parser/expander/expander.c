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

#include "../../../includes/parser.h"

static t_expander	*init_expander(void)
{
	t_expander	*expander;

	expander = malloc(sizeof(t_expander));
	expander->start = 0;
	expander->end = 0;
	expander->ret = NULL;
	return (expander);
}

static void	expand_exit_code(t_expander *expander, t_pipe *pipe)
{
	char	*itoa;

	itoa = ft_itoa(pipe->exit_status);
	expander->tmp = ft_strjoin(expander->ret, itoa);
	free(itoa);
	free(expander->ret);
	expander->ret = ft_strdup(expander->tmp);
	free(expander->tmp);
	expander->start++;
	expander->end = expander->start;
}

static void	expand_copy(t_expander *expander, char *str)
{
	char	*tmp;

	tmp = ft_substr(str, expander->end, expander->start - (expander->end));
	expander->tmp = ft_strjoin(expander->ret, tmp);
	free(tmp);
	if (expander->ret)
	{
		free(expander->ret);
		expander->ret = NULL;
	}
	expander->ret = ft_strdup(expander->tmp);
	free(expander->tmp);
}

static void	expand_var(t_expander *expander, char *str, t_env *envp)
{
	char	*var_name;
	char	*tmp;

	var_name = NULL;
	var_name = verify_syntax(str, expander);
	if (var_name != NULL)
	{
		expander->var = get_env(envp, var_name);
		free(var_name);
	}
	else
		expander->var = NULL;
	expander->tmp = ft_strjoin(expander->ret, expander->var);
	free(expander->var);
	tmp = ft_strdup(expander->tmp);
	free(expander->tmp);
	expander->tmp = clean_expand(tmp);
	free(tmp);
	ft_strlcpy(expander->ret, expander->tmp, ft_strlen(expander->tmp) + 1);
	free(expander->tmp);
	expander->start = expander->end;
}

char	*expander(char *str, t_env *envp, t_pipe *pipe)
{
	t_expander	*expander;
	char		*ret;

	expander = init_expander();
	while (str[expander->start])
	{
		if (str[expander->start] == '$'
			&& !is_special_dollar_char(str[expander->start + 1]))
		{
			expand_copy(expander, str);
			expander->end = expander->start;
			if (str[++expander->start] == '?')
				expand_exit_code(expander, pipe);
			else
				expand_var(expander, str, envp);
		}
		else
			expander->start++;
	}
	ret = ft_strjoin(expander->ret, str + expander->end);
	free(expander->ret);
	free(expander);
	return (ret);
}
