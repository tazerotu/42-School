/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:28:19 by ttas              #+#    #+#             */
/*   Updated: 2024/03/21 14:43:11 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha_numeric(char c, char c2)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && (c2 < '0'
			|| (c2 > '9' && c2 < 'A') || (c2 > 'Z' && c2 < 'a') || c2 > 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	if (str[0] != '\0' && str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (is_alpha_numeric(str[i], str[i - 1]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}
