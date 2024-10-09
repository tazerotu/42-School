/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:42 by ttas              #+#    #+#             */
/*   Updated: 2024/10/09 12:18:14 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}					t_pos;

typedef struct s_map
{
	int				fd_map;
	unsigned int	x;
	unsigned int	y;
	unsigned int	coins;
	unsigned int	moves;
	t_pos			*exit;
	t_character		*player;
	t_character		*ghost1;
	t_character		*ghost2;
	t_character		*ghost3;
	char			**map;
	char			**floodfill;
	t_mlx			mlx;
}					t_map;

int	isValidMove(int x, int y, t_map *map, int **visited)
{
	if (x >= 0 && x < map->x && y >= 0 && y < map->y && map[x][y] != '1'
		&& !visited[x][y])
	{
		return (1);
	}
	return (0);
}

int	bfs(t_pos *start, t_pos *goal, t_map *map)
{
	return (0); // Path not found
}
