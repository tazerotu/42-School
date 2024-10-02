/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/10/02 11:39:26 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

void	kill_switch(t_map *map)
{
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	mlx_destroy_display(map->mlx.mlx);
	free(map->exit);
	free(map->player->pos);
	free(map->player);
	free(map->map);
	free(map->mlx.mlx);
	free(map->mlx.win);
	free(map);
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_message(INVALID_INPUT);
	t_map *map;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_message(INVALID);
	init_map(argv, map);
	map->mlx.mlx = mlx_init();
	if (!map->mlx.mlx)
		error(INVALID_MLX_INIT);
	map->mlx.win = mlx_new_window(map->mlx.mlx, 1280, 720, "Hello world!");
	printf("X : %d\n", map->x);
	printf("Y : %d\n", map->y);
	for (unsigned int i = 0; i < map->y; i++)
		printf("map[%d] : %s", map->y - i, map->map[i]);
	printf("\nCoins : %d\n", map->coins);
	printf("\n");
	mlx_hook(map->mlx.win, 2, (1L << 0), keypress, map);
	mlx_loop(map->mlx.mlx);
	kill_switch(map);
	return (0);
}