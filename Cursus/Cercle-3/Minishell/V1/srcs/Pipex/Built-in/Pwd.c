/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:07 by ttas              #+#    #+#             */
/*   Updated: 2025/01/29 17:02:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

char *pwd(void)
{
	char str[1000];
	char *test;
	test = getcwd(str, sizeof(str));
	test = ft_strnstr(test, "Minishell");
	int i = value;
	while(test[i])
		i++;
	char *ret = malloc((i - value) * sizeof(char));
	i = 0;
	while(test[value])
	{
		ret[i] = test[value];
		value++;
		i++;
	}
	return(ret);
}

// int main(void)
// {
// 	char *str;
// 	str = pwd();
// 	printf("%s\n", str);
// 	return 0;
// }