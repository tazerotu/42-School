/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:01:18 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 10:22:56 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	wall_set1(t_map *map, int i, int j, int N, int So, int E, int We)
{
	if (N == 1 && So == 1 && E == 1)
		int wall_draw(map, WALL_FACE_TOP_RIGHT_BOTTOM);
	else if (N == 1 && So == 1 && We == 1)
	{
		map->floodfill[i][j] = WALL_FACE_TOP_BOTTOM_LEFT;
	}
	else if (N == 1 && E == 1 && We == 1)
	{
		map->floodfill[i][j] = WALL_FACE_TOP_LEFT_RIGHT;
	}
	else if (So == 1 && E == 1 && We == 1)
	{
		map->floodfill[i][j] = WALL_FACE_BOTTOM_LEFT_RIGHT;
	}
	else if (N == 1 && So == 1)
	{
		map->floodfill[i][j] = WALL_FACE_TOP_BOTTOM;
	}
}

void	wall_set2(t_map *map, int i, int j, int N, int So, int E, int We)
{
	if (E == 1 && We == 1)
	{
		map->floodfill[i][j] = WALL_FACE_LEFT_RIGHT;
	}
	else if (N == 1 && E == 1)
	{
		map->floodfill[i][j] = WALL_FACE_TOP_LEFT;
	}
	else if (N == 1 && We == 1)
	{
		map->floodfill[i][j] = WALL_FACE_TOP_RIGHT;
	}
	else if (So == 1 && E == 1)
	{
		map->floodfill[i][j] = WALL_FACE_BOTTOM_LEFT;
	}
}

void	wall_set3(t_map *map, int i, int j, int N, int So, int E, int We)
{
	if (So == 1 && We == 1)
	{
		map->floodfill[i][j] = WALL_FACE_BOTTOM_RIGHT;
	}
	else if (N == 1)
	{
		map->floodfill[i][j] = WALL_FACE_TOP;
	}
	else if (So == 1)
	{
		map->floodfill[i][j] = WALL_FACE_BOTTOM;
	}
	else if (E == 1)
	{
		map->floodfill[i][j] = WALL_FACE_RIGHT;
	}
	else if (We == 1)
	{
		map->floodfill[i][j] = WALL_FACE_LEFT;
	}
}

void	wall_check(t_map *map, int i, int j)
{
	int	N;
	int	So;
	int	E;
	int	We;

	N = 0;
	So = 0;
	E = 0;
	We = 0;
	// Check sides to see which wall type to use
	if (map->map[i][j] == '1' && j < map->y - 1 && map->map[i][j + 1] == '1')
		N = 1;
	if (map->map[i][j] == '1' && j > 0 && map->map[i][j - 1] == '1')
		So = 1;
	if (map->map[i][j] == '1' && i < map->x - 1 && map->map[i + 1][j] == '1')
		E = 1;
	if (map->map[i][j] == '1' && i > 0 && map->map[i - 1][j] == '1')
		We = 1;
	wall_set1(map, i, j, N, So, E, We);
	wall_set2(map, i, j, N, So, E, We);
	wall_set3(map, i, j, N, So, E, We);
}
