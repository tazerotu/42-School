/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:05:40 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 11:27:59 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	keypress(int keycode, t_map *map)
{
	if (keycode == W || keycode == ARROW_UP)
		move_up(map);
	if (keycode == S || keycode == ARROW_DOWN)
		move_down(map);
	if (keycode == D || keycode == ARROW_RIGHT)
		move_right(map);
	if (keycode == A || keycode == ARROW_LEFT)
		move_left(map);
	for (unsigned int i = 0; i < map->y; i++)
		printf("map[%d] : %s", i, map->map[i]);
	printf("\n");
	printf("\n");
	return (0);
}

void	move_up(t_map *map)
{
	if (map->player->pos->y == map->y)
		return ;
	map->map[map->player->pos->y][map->player->pos->x] = '0';
	map->player->pos->y++;
	map->map[map->player->pos->y][map->player->pos->x] = 'P';
}

void	move_down(t_map *map)
{
	if (map->player->pos->y == 0)
		return ;
	map->map[map->player->pos->y][map->player->pos->x] = '0';
	map->player->pos->y--;
	map->map[map->player->pos->y][map->player->pos->x] = 'P';
}

void	move_left(t_map *map)
{
	if (map->player->pos->x == 0)
		return ;
	map->map[map->player->pos->y][map->player->pos->x] = '0';
	map->player->pos->x--;
	map->map[map->player->pos->y][map->player->pos->x] = 'P';
}

void	move_right(t_map *map)
{
	if (map->player->pos->x == 0)
		return ;
	map->map[map->player->pos->y][map->player->pos->x] = '0';
	map->player->pos->x++;
	map->map[map->player->pos->y][map->player->pos->x] = 'P';
}
