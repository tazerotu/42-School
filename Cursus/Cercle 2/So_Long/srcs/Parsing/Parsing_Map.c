/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:43:10 by ttas              #+#    #+#             */
/*   Updated: 2024/07/25 10:40:07 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	parsing_map_size(char *path)
{
	char *buffer;
	unsigned int i;
	unsigned int j;

	buffer = get_next_line(open(path, O_RDONLY));
	j = 0;
	i = ft_strlen(buffer);
	while (buffer)
	{
		printf("%s\n", buffer);
		if (i != ft_strlen(buffer))
			return (INVALID_MAP_SIZE);
		buffer = get_next_line(open(path, O_RDONLY));
		j++;
	}
	return (VALID_MAP_SIZE);
}