/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:10:04 by ttas              #+#    #+#             */
/*   Updated: 2024/05/07 10:32:59 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*isempty(char const *s1, char const *set)
{
	char	*new_str;

	if (set == 0 && s1 == 0)
		return (0);
	else if (s1 == 0)
		return (0);
	else
	{
		new_str = malloc(ft_strlen(s1) + 1);
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
		return (new_str);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	finish;

	if (s1 == 0 || set == 0)
		return (isempty(s1, set));
	start = 0;
	finish = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (finish > start && ft_strchr(set, s1[finish - 1]))
		finish--;
	return (ft_substr(s1, start, finish - start));
}
