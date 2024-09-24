/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloodFill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:32 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 10:24:18 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

t_map	floodfill(t_map *map)
{
	int	i;

	i = 0;
	map->floodfill = malloc(map->y * sizeof(char));
	while (i < map->y)
	{
		map->floodfill[i] = malloc(map->x * sizeof(char));
		i++;
	}
	wall_init(map, 0, 0);
	return (*map);
}

void	wall_init(t_map *map, int i, int j)
{
	if (i < 0 || j < 0 || (unsigned int)i > map->x || (unsigned int)j > map->y)
		return ;
	wall_check(map, i, j);
	wall_init(map, i + 1, j);
	wall_init(map, i - 1, j);
	wall_init(map, i, j + 1);
	wall_init(map, i, j - 1);
}

void	wall_check(t_map *map, int i, int j)
{
	int	N;
	int	S;
	int	E;
	int	W;

	N = 0;
	S = 0;
	E = 0;
	W = 0;
	// Check sides to see which wall type to use
	if (map->map[i][j] == 1 && map->map[i][j + 1] == 1 && j < map->y)
		N = 1;
	if (map->map[i][j] == 1 && map->map[i][j - 1] == 1 && j > 0)
		S = 1;
	if (map->map[i][j] == 1 && map->map[i + 1][j] == 1 && i < map->x)
		E = 1;
	if (map->map[i][j] == 1 && map->map[i - 1][j] == 1 && i > 0)
		W = 1;

		
	// Set correct Wall type
}

