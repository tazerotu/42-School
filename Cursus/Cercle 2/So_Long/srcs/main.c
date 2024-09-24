/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 11:11:52 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_message(INVALID_INPUT);
	t_map *map;
	map = (t_map *)malloc(sizeof(t_map));
	init_map(argv, map);
	map->mlx = mlx_init();
	map->mlx->win = mlx_new_window(map->mlx, 1280, 720, "Hello world!");
	if (!map)
		error_message(INVALID);
	printf("X : %d\n", map->x);
	printf("Y : %d\n", map->y);
	for (unsigned int i = 0; i < map->y; i++)
		printf("map[%d] : %s", i, map->map[i]);
	printf("\nCoins : %d\n", map->coins);
	printf("\n");
	mlx_hook(map->mlx->win, 2, (1L << 0), keypress, map);
	mlx_loop(map->mlx);
	free(map->exit);
	free(map->player);
	free(map->map);
	free(map);
	return (0);
}