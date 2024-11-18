/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:01:18 by ttas              #+#    #+#             */
/*   Updated: 2024/11/18 20:51:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

// void	wall_set1(t_map *map, int i, int j, int orientation)
// {
// 	if (orientation == 111)
// 		wall_draw(map, WALL_FACE_TOP_RIGHT_BOTTOM, i, j);
// 	else if (orientation == 1011)
// 	{
// 		wall_draw(map, WALL_FACE_TOP_BOTTOM_LEFT, i, j);
// 	}
// 	else if (orientation == 1101)
// 	{
// 		wall_draw(map, WALL_FACE_TOP_LEFT_RIGHT, i, j);
// 	}
// 	else if (orientation == 1110)
// 	{
// 		wall_draw(map, WALL_FACE_BOTTOM_LEFT_RIGHT, i, j);
// 	}
// 	else if (orientation == 11)
// 	{
// 		wall_draw(map, WALL_FACE_TOP_BOTTOM, i, j);
// 	}
// }

// void	wall_set2(t_map *map, int i, int j, int orientation)
// {
// 	if (orientation == 1100)
// 	{
// 		wall_draw(map, WALL_FACE_LEFT_RIGHT, i, j);
// 	}
// 	else if (orientation == 1001)
// 	{
// 		wall_draw(map, WALL_FACE_TOP_LEFT, i, j);
// 	}
// 	else if (orientation == 101)
// 	{
// 		wall_draw(map, WALL_FACE_TOP_RIGHT, i, j);
// 	}
// 	else if (orientation == 1010)
// 	{
// 		wall_draw(map, WALL_FACE_BOTTOM_LEFT, i, j);
// 	}
// }

// void	wall_set3(t_map *map, int i, int j, int orientation)
// {
// 	if (orientation ==  1100)
// 	{
// 		wall_draw(map, WALL_FACE_BOTTOM_RIGHT, i, j);
// 	}
// 	else if (orientation ==  1)
// 	{
// 		wall_draw(map, WALL_FACE_TOP, i, j);
// 	}
// 	else if (orientation == 10)
// 	{
// 		wall_draw(map, WALL_FACE_BOTTOM, i, j);
// 	}
// 	else if (orientation == 100)
// 	{
// 		wall_draw(map, WALL_FACE_RIGHT, i, j);
// 	}
// 	else if (orientation == 1000)
// 	{
// 		wall_draw(map, WALL_FACE_LEFT, i, j);
// 	}
// 	else if (orientation == 0)
// 	{
// 		wall_draw(map, GROUND, i, j);
// 	}
	
// }

/*
North = 1
South = 10
East = 100
West = 1000
*/

void	wall_check(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (map->floodfill[j][i] == '1')
			{
				wall_draw(map, WALL, i, j);	
			}
			j++;
		}
		i++;
	}
}
/*
				if (j < map->y - 1 && map->floodfill[j + 1][i] == '1')
					orientation += 1;
				if (j > 0 && map->floodfill[j - 1][i] == '1')
					orientation += 10;
				if (i < map->x - 1 && map->floodfill[j][i + 1] == '1')
					orientation += 100;
				if (i > 0 && map->floodfill[j][i - 1] == '1')
					orientation += 1000;
				wall_set1(map, i, j, orientation);
				wall_set2(map, i, j, orientation);
				wall_set3(map, i, j, orientation);
*/
// void	wall_check(t_map *map, int i, int j)
// {
// 	int	N;
// 	int	So;
// 	int	E;
// 	int	We;

// 	N = 0;
// 	So = 0;
// 	E = 0;
// 	We = 0;
// 	if (map->floodfill[j][i] == '1' && j < map->y - 1 && map->floodfill[j][i
// 		+ 1] == '1')
// 		N = 1;
// 	if (map->floodfill[j][i] == '1' && j > 0 && map->floodfill[j][i - 1] == '1')
// 		So = 1;
// 	if (map->floodfill[j][i] == '1' && i < map->x - 1 && map->floodfill[j
// 		+ 1][i] == '1')
// 		E = 1;
// 	if (map->floodfill[j][i] == '1' && i > 0 && map->floodfill[j - 1][i] == '1')
// 		We = 1;
// 	map->floodfill[j][i] = 'W';
// 	wall_set1(map, i, j, N, So, E, We);
// 	wall_set2(map, i, j, N, So, E, We);
// 	wall_set3(map, i, j, N, So, E, We);
// }

// void	wall_init(t_map *map, int x, int y)
// {
// 	if(overflow(map, x, y) == -1 || map->floodfill[y][x] == 'F' || map->floodfill[y][x] == 'W')
// 		return ;
// 	if(map->floodfill[y][x] == '1')
// 		map->floodfill[y][x] = 'W';
// 	wall_init(map, x + 1, y);
// 	wall_init(map, x - 1, y);
// 	wall_init(map, x, y + 1);
// 	wall_init(map, x, y - 1);
// }
