/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:43:10 by ttas              #+#    #+#             */
/*   Updated: 2024/08/05 17:21:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	parsing_map_size(t_map *map)
{
	char *buffer;
	unsigned int i;
	unsigned int j;
	j = 0;
	buffer = get_next_line(map->fd_map);
	i = ft_strlen(buffer);
	while (buffer)
	{
		if (!buffer && i != ft_strlen(buffer))
		{
			free(buffer);
			return (INVALID_MAP_SIZE);
		}
		free(buffer);
		buffer = get_next_line(map->fd_map);
		j++;
	}
	free(buffer);
	close(map->fd_map);
	i--;
	map->x = i;
	map->y = j;
	return (VALID_MAP_SIZE);
}