/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:43:10 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 09:07:57 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	parsing_map_size(char **argv, t_map *map)
{
	char			*buffer;
	unsigned int	i;
	unsigned int	j;
	int				fd_map;

	j = 0;
	fd_map = open(argv[1], O_RDONLY);
	if (!fd_map)
		error_message(INVALID_INPUT);
	buffer = get_next_line(fd_map);
	i = ft_strlen(buffer);
	while (buffer)
	{
		if (!buffer && i != ft_strlen(buffer))
			error_message(INVALID_MAP_SIZE);
		free(buffer);
		buffer = get_next_line(fd_map);
		j++;
	}
	close(fd_map);
	i--;
	map->x = i;
	map->y = j;
	return (VALID_MAP_SIZE);
}

int	parsing_map_init(char **argv, t_map *map)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	map->fd_map = open(argv[1], O_RDONLY);
	if (!map->fd_map)
		error_message(INVALID_INPUT);
	map->map = (char **)malloc(sizeof(char *) * (map->y + 1));
	buffer = get_next_line(map->fd_map);
	while (buffer)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
		map->map[i] = ft_strdup(buffer);
		free(buffer);
		buffer = get_next_line(map->fd_map);
		i++;
	}
	close(map->fd_map);
	map->map[i] = NULL;
	return (VALID_MAP_FLOODFILL);
}

int	parsing_map_closed(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		if (map->map[i][0] != '1' || map->map[i][map->x - 1] != '1')
			error_message(INVALID_MAP_CLOSE);
		i++;
	}
	while (j < map->x)
	{
		if (map->map[0][j] != '1' || map->map[map->y - 1][j] != '1')
			error_message(INVALID_MAP_CLOSE);
		j++;
	}
	return (VALID_MAP_CLOSE);
}
