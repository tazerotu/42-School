/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:05:40 by ttas              #+#    #+#             */
/*   Updated: 2024/11/18 14:47:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	keypress(int keycode, t_map *map)
{
	int	i;

	i = 0;
	// if(map->win == -1 && keycode == 114)
	// else if (map->win != -1)
	// {
	if (keycode == W || keycode == ARROW_UP)
		move(map, 0, -1, PLAYER_UP);
	if (keycode == S || keycode == ARROW_DOWN)
		move(map, 0, 1, PLAYER_DOWN);
	if (keycode == D || keycode == ARROW_RIGHT)
		move(map, 1, 0, PLAYER_RIGHT);
	if (keycode == A || keycode == ARROW_LEFT)
		move(map, -1, 0, PLAYER_LEFT);
	if (keycode == ESC)
		kill_switch(map);
	while (i < map->y)
	{
		ft_printf("map[%d] : %s", map->y - i, map->map[i]);
		i++;
	}
	ft_printf("\nCoins : %d\n", map->coins);
	ft_printf("Moves : %d\n", map->moves);
	ft_printf("\n");
	// }
	return (0);
}

void	move(t_map *map, int x, int y, void *dir)
{
	map->moves++;
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
	player_draw(map, dir, x, y);
	map->map[map->player->pos->y][map->player->pos->x] = '0';
	map->player->pos->x += x;
	map->player->pos->y += y;
	map->map[map->player->pos->y][map->player->pos->x] = 'P';
}
