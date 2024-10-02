/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloodFill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:32 by ttas              #+#    #+#             */
/*   Updated: 2024/10/02 08:59:44 by ttas             ###   ########.fr       */
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
	if (map->map[i][j] == '1' && j < map->y - 1 && map->map[i][j + 1] == '1')
		N = 1;
	if (map->map[i][j] == '1' && j > 0 && map->map[i][j - 1] == '1')
		S = 1;
	if (map->map[i][j] == '1' && i < map->x - 1 && map->map[i + 1][j] == '1')
		E = 1;
	if (map->map[i][j] == '1' && i > 0 && map->map[i - 1][j] == '1')
		W = 1;
	// Set correct Wall type
	if (N && S && E && W)
		map->floodfill[i][j] = 'X'; // Surrounded by walls
	else if (N && S && E)
		map->floodfill[i][j] = 'T'; // T-junction
	else if (N && S && W)
		map->floodfill[i][j] = 'T'; // T-junction
	else if (N && E && W)
		map->floodfill[i][j] = 'T'; // T-junction
	else if (S && E && W)
		map->floodfill[i][j] = 'T'; // T-junction
	else if (N && S)
		map->floodfill[i][j] = '|'; // Vertical wall
	else if (E && W)
		map->floodfill[i][j] = '-'; // Horizontal wall
	else if (N && E)
		map->floodfill[i][j] = '┌'; // Corner
	else if (N && W)
		map->floodfill[i][j] = '┐'; // Corner
	else if (S && E)
		map->floodfill[i][j] = '└'; // Corner
	else if (S && W)
		map->floodfill[i][j] = '┘'; // Corner
	else if (N)
		map->floodfill[i][j] = '^'; // Top end
	else if (S)
		map->floodfill[i][j] = 'v'; // Bottom end
	else if (E)
		map->floodfill[i][j] = '>'; // Right end
	else if (W)
		map->floodfill[i][j] = '<'; // Left end
}
