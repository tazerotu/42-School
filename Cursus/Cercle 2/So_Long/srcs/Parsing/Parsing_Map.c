/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:43:10 by ttas              #+#    #+#             */
/*   Updated: 2024/08/15 10:48:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	parsing_map_size(char **argv, t_map *map)
{
	char *buffer;
	unsigned int i;
	unsigned int j;
	j = 0;
	map->fd_map = open(argv[1], O_RDONLY);
	if (!map->fd_map)
		error_message(INVALID_INPUT);
	buffer = get_next_line(map->fd_map);
	i = ft_strlen(buffer);
	while (buffer)
	{
		if (!buffer && i != ft_strlen(buffer))
			error_message(INVALID_MAP_SIZE);
		free(buffer);
		buffer = get_next_line(map->fd_map);
		j++;
	}
	close(map->fd_map);
	i--;
	map->x = i;
	map->y = j;
	return (VALID_MAP_SIZE);
}

int parsing_map_init(char **argv, t_map *map)
{
	char *buffer;
	unsigned int i;
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

int parsing_map_collectibles(t_map *map)
{
	unsigned int i;
	unsigned int j;
	i = 0;
	j = 0;
	map->coins = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'P')
			{
				map->p_start = malloc(sizeof(struct s_pos));
				map->p_start->x = j;
				map->p_start->y = i;
			}
			if (map->map[i][j] == 'E')
			{
				map->exit = malloc(sizeof(struct s_pos));
				map->exit->x = j;
				map->exit->y = i;
			}
			if (map->map[i][j] == 'C')
				map->coins++;
			j++;
		}
		j = 0;
		i++;
	}
	return (VALID_MAP_COLLECTIBLES);
}
