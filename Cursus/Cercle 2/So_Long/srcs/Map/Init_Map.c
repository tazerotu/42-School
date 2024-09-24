/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:53 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 09:08:10 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	init_map(char **argv, t_map *map)
{
	parsing_map_size(argv, map);
	parsing_map_init(argv, map);
	parsing_map_closed(map);
	parsing_map_char(map);
	parsing_map_char_player(map);
	parsing_map_char_exit(map);
	init_map_collectibles(map);
	init_map_char_player(map);
	init_map_char_exit(map);
	//	floodfill(map);
	return (VALID);
}

int	init_map_collectibles(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	map->coins = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'C')
				map->coins++;
			j++;
		}
		j = 0;
		i++;
	}
	if (map->coins == 0)
		error_message(INVALID_MAP_COLLECTIBLES);
	return (VALID_MAP_COLLECTIBLES);
}

int	init_map_char_player(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'P')
			{
				map->player = malloc(sizeof(t_character));
				map->player->pos = malloc(sizeof(t_pos));
				if (map->player->pos == NULL)
					return (INVALID_MAP_PLAYER);
				map->player->pos->x = j;
				map->player->pos->y = i;
				return (VALID_MAP_PLAYER);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (INVALID_MAP_PLAYER);
}

int	init_map_char_exit(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'E')
			{
				map->exit = malloc(sizeof(t_pos));
				map->exit->x = j;
				map->exit->y = i;
				return (VALID_MAP_EXIT);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (INVALID_MAP_EXIT);
}
