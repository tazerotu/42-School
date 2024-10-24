/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloodFill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:32 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 10:05:09 by ttas             ###   ########.fr       */
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
	if (i < 0 || j < 0 || i > map->x || j > map->y)
		return ;
	wall_check(map, i, j);
	wall_init(map, i + 1, j);
	wall_init(map, i - 1, j);
	wall_init(map, i, j + 1);
	wall_init(map, i, j - 1);
}
