/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:43:10 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 11:14:41 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	parsing_map_size(char *path, t_map *map)
{
	int fd;
	char *buffer;
	map = NULL;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	fd = open(path, O_RDONLY);
	if (!fd)
		error_message(INVALID_INPUT);
	k = 0;
	j = 0;
	buffer = get_next_line(fd);
	i = ft_strlen(buffer);
	while (buffer)
	{
		if (!buffer && i != ft_strlen(buffer))
			return (INVALID_MAP_SIZE);
		k = 0;
		while (buffer[k] != '\0')
		{
			if (buffer[k] == 'P' || buffer[k] == 'E')
				init_map(k, j, buffer[k], map);
			k++;
		}
		buffer = get_next_line(fd);
		j++;
	}
	free(buffer);
	close(fd);
	init_map(i, (j - 1), 'S', map);
	return (VALID_MAP_SIZE);
}