/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:01:11 by marvin            #+#    #+#             */
/*   Updated: 2024/06/30 22:01:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char to_upper(char c)
{
	if(c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return c;
}

char to_lower(char c)
{
	if(c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return c;
}

int is_alpha(char c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return 1;
	return -1;
}

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		int i = 1, j = 0;
		while (argv[i])
		{
			char c;
			while (is_alpha(argv[i][j]) != 1)
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			c = to_upper(argv[i][j]);
			write(1, &c, 1);
			j++;
			while (is_alpha(argv[i][j]) == 1)
			{
				c = to_lower(argv[i][j]);
				write(1, &c, 1);
				j++;
			}
			i++;
		}
		
	}
	write(1, "\n", 1);
}