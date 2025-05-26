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

static t_expander	*expand_exit_code(t_expander *expander, t_pipe *pipe)
{
	char	*itoa;

	itoa = ft_itoa(pipe->exit_status);
	expander->tmp = ft_strjoin(expander->ret, itoa);
	free(itoa);
	ft_strlcpy(expander->ret, expander->tmp, ft_strlen(expander->tmp) + 1);
	free(expander->tmp);
	expander->start++;
	expander->end = expander->start;
	expander->dollar = 1;
	return (expander);
}

static t_expander	*expand_copy(t_expander *expander, char *str)
{
	char	*tmp;

	expander->dollar = 0;
	tmp = ft_substr(str, expander->end, expander->start - (expander->end));
	expander->tmp = ft_strjoin(expander->ret, tmp);
	free(tmp);
	expander->ret = ft_strdup(expander->tmp);
	free(expander->tmp);
	return (expander);
}

static t_expander	*expand_var(t_expander *expander, char *str, t_env *envp)
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
	free(expander->ret);
	free(expander->var);
	tmp = ft_strjoin(expander->ret, expander->tmp);
	free(expander->tmp);
	expander->tmp = clean_expand(tmp)
	free(tmp);
	ft_strlcpy(expander->ret, expander->tmp, ft_strlen(expander->tmp) + 1);
	free(expander->tmp);
	expander->start = expander->end;
	return (expander);
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
			expander = expand_copy(expander, str);
			expander->end = expander->start;
			if (str[++expander->start] == '?')
				expander = expand_exit_code(expander, pipe);
			else
				expander = expand_var(expander, str, envp);
		}
		else
			expander->start++;
	}
	ret = ft_strjoin(expander->ret, str + expander->end);
	if (expander->dollar == 1)
		free(expander->ret);
	free(expander);
	return (ret);
}

/*
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
*/

/*
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
// , t_env *envp
char	*replace_variable(char *ret, char *var)
{
	// char	*value;
	char	*tmp;

	// value = get_env(envp, var);
	tmp = ft_strjoin(ret, var);
	free(var);
	// free(value);
	free(ret);
	ret = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (ret);
}

char	*expander(char *str, t_env *envp, t_pipe *pipe)
{
	char	*ret;
	t_expander	*expander;

	expander = malloc(sizeof(t_expander));
	expander->ret = NULL;
	expander->start = 0;
	expander->end = 0;
	while (str[expander->start])
	{
		if (str[expander->start++] == '$')
		{
			if(str[expander->start] == '?')
			{
				expander->ret = replace_variable
				(expander->ret, ft_itoa(pipe->exit_status));
			}
			else
			{
				expander->ret = malloc(sizeof(char) * (expander->start + 1));
				ft_strlcpy(expander->ret, str, expander->start);
				expander->var = extract_variable
				(str, &expander->start, &expander->end);
				if (expander->var)
					expander->ret = replace_variable
					(expander->ret, get_env(envp, expander->var));
			}
		}
	}
	ret = ft_strjoin(expander->ret, str + expander->end);
	return (ret);
}
*/

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