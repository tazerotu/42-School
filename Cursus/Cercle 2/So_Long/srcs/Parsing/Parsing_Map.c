/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:43:10 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:54:43 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	parsing_map_size(char *path, t_map *map)
{
	int fd;
	char *buffer;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	fd = open(path, O_RDONLY);

	buffer = get_next_line(fd);
	k = 0;
	j = 0;
	i = ft_strlen(buffer);
	while (buffer)
	{
		k = 0;
		while (buffer[k] != '\0')
		{
			if (buffer[k] == 'P' || buffer[k] == 'E')
				init_map(k, j, buffer[k], map);
			k++;
		}
		if (i != ft_strlen(buffer))
			return (INVALID_MAP_SIZE);
		buffer = get_next_line(fd);
		j++;
	}
	printf("%d", j);
	init_map(i, j, 'S', map);
	return (VALID_MAP_SIZE);
}