/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloodFill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:32 by ttas              #+#    #+#             */
/*   Updated: 2024/11/19 09:53:48 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

static int	parsing_exit_path(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	if (overflow(map, x, y) == -1 || map->floodfill[y][x] == 'F'
		|| map->floodfill[y][x] == '1')
		return (0);
	if (map->floodfill[y][x] == 'P')
		return (1);
	if (map->floodfill[y][x] == '0' || map->floodfill[y][x] == 'C')
		map->floodfill[y][x] = 'F';
	i += parsing_exit_path(map, x + 1, y);
	i += parsing_exit_path(map, x - 1, y);
	i += parsing_exit_path(map, x, y + 1);
	i += parsing_exit_path(map, x, y - 1);
	return (i);
}

void	parsing_map_exit_path(t_map *map)
{
	if (parsing_exit_path(map, map->exit->x, map->exit->y) == 0)
		error_message(-205);
}
