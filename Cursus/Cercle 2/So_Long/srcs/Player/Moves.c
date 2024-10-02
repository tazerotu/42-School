/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:05:40 by ttas              #+#    #+#             */
/*   Updated: 2024/10/02 10:51:06 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	keypress(int keycode, t_map *map)
{
	if (keycode == W || keycode == ARROW_UP)
		move(map, 0, -1);
	if (keycode == S || keycode == ARROW_DOWN)
		move(map, 0, 1);
	if (keycode == D || keycode == ARROW_RIGHT)
		move(map, 1, 0);
	if (keycode == A || keycode == ARROW_LEFT)
		move(map, -1, 0);
	if (keycode == ESC)
		return (0);
	for (unsigned int i = 0; i < map->y; i++)
		printf("map[%d] : %s", map->y - i, map->map[i]);
	printf("\nCoins : %d\n", map->coins);
	printf("\n");
	return (0);
}

void	move(t_map *map, int x, int y)
{
	if (map->map[map->player->pos->y + y][map->player->pos->x + x] == 'E')
	{
		player_win(map);
		y = 0;
		x = 0;
	}
	if (map->map[map->player->pos->y + y][map->player->pos->x + x] == '1')
		return ;
	if (map->map[map->player->pos->y + y][map->player->pos->x + x] == 'C')
		map->coins--;
	map->map[map->player->pos->y][map->player->pos->x] = '0';
	map->player->pos->x += x;
	map->player->pos->y += y;
	map->map[map->player->pos->y][map->player->pos->x] = 'P';
}
