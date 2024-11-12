/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:01:18 by ttas              #+#    #+#             */
/*   Updated: 2024/11/12 10:15:44 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	wall_set1(t_map *map, int i, int j, int N, int So, int E, int We)
{
	if (N == 1 && So == 1 && E == 1)
		wall_draw(map, WALL_FACE_TOP_RIGHT_BOTTOM, i, j);
	else if (N == 1 && So == 1 && We == 1)
	{
		wall_draw(map, WALL_FACE_TOP_BOTTOM_LEFT, i, j);
	}
	else if (N == 1 && E == 1 && We == 1)
	{
		wall_draw(map, WALL_FACE_TOP_LEFT_RIGHT, i, j);
	}
	else if (So == 1 && E == 1 && We == 1)
	{
		wall_draw(map, WALL_FACE_BOTTOM_LEFT_RIGHT, i, j);
	}
	else if (N == 1 && So == 1)
	{
		wall_draw(map, WALL_FACE_TOP_BOTTOM, i, j);
	}
}

void	wall_set2(t_map *map, int i, int j, int N, int So, int E, int We)
{
	if (E == 1 && We == 1)
	{
		wall_draw(map, WALL_FACE_LEFT_RIGHT, i, j);
	}
	else if (N == 1 && E == 1)
	{
		wall_draw(map, WALL_FACE_TOP_LEFT, i, j);
	}
	else if (N == 1 && We == 1)
	{
		wall_draw(map, WALL_FACE_TOP_RIGHT, i, j);
	}
	else if (So == 1 && E == 1)
	{
		wall_draw(map, WALL_FACE_BOTTOM_LEFT, i, j);
	}
}

void	wall_set3(t_map *map, int i, int j, int N, int So, int E, int We)
{
	if (So == 1 && We == 1)
	{
		wall_draw(map, WALL_FACE_BOTTOM_RIGHT, i, j);
	}
	else if (N == 1)
	{
		wall_draw(map, WALL_FACE_TOP, i, j);
	}
	else if (So == 1)
	{
		wall_draw(map, WALL_FACE_BOTTOM, i, j);
	}
	else if (E == 1)
	{
		wall_draw(map, WALL_FACE_RIGHT, i, j);
	}
	else if (We == 1)
	{
		wall_draw(map, WALL_FACE_LEFT, i, j);
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
	if (map->floodfill[j][i] == '1' && j < map->y - 1 && map->floodfill[j][i
		+ 1] == '1')
		N = 1;
	if (map->floodfill[j][i] == '1' && j > 0 && map->floodfill[j][i - 1] == '1')
		So = 1;
	if (map->floodfill[j][i] == '1' && i < map->x - 1 && map->floodfill[j
		+ 1][i] == '1')
		E = 1;
	if (map->floodfill[j][i] == '1' && i > 0 && map->floodfill[j - 1][i] == '1')
		We = 1;
	wall_set1(map, i, j, N, So, E, We);
	wall_set2(map, i, j, N, So, E, We);
	wall_set3(map, i, j, N, So, E, We);
}

void	wall_init(t_map *map, int i, int j)
{
	if (overflow(map, i, j) == 1 || map->floodfill[j][i] == 'F')
		return ;
	wall_check(map, i, j);
	wall_init(map, i + 1, j);
	wall_init(map, i - 1, j);
	wall_init(map, i, j + 1);
	wall_init(map, i, j - 1);
}
