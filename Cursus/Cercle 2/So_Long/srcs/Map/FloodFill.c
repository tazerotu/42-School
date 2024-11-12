/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloodFill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:32 by ttas              #+#    #+#             */
/*   Updated: 2024/11/12 10:29:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

static int parsing_exit_path(t_map *map, int x, int y)
{
	if(overflow(map, x, y) == -1 || map->floodfill[y][x] == 'F')
		return 0;
	if(map->floodfill[y][x] == '0' || map->floodfill[y][x] == 'C')
		map->floodfill[y][x] = 'F';
	if(map->floodfill[y][x] == 'P')
		return (1);
	parsing_exit_path(map, x + 1, y);
	parsing_exit_path(map, x - 1, y);
	parsing_exit_path(map, x, y + 1);
	parsing_exit_path(map, x, y - 1);
	return 0;
}

void parsing_map_exit_path(t_map *map)
{
	if(parsing_exit_path(map, map->exit->x, map->exit->y) == 0)
		error_message(-205);
}