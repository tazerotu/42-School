/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/10/02 12:36:27 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

void	init_malloc(t_map *map)
{
	map->moves = 0;
	map->player = malloc(sizeof(t_character));
	if (map->player == NULL)
		error_message(INVALID_MAP_PLAYER);
	map->player->pos = malloc(sizeof(t_pos));
	if (map->player->pos == NULL)
		error_message(INVALID_MAP_PLAYER);
	return ;
}

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
	unsigned int	i;
	t_map			*map;

	i = 0;
	if (argc != 2)
		error_message(INVALID_INPUT);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_message(INVALID);
	init_malloc(map);
	init_map(argv, map);
	map->mlx.mlx = mlx_init();
	if (!map->mlx.mlx)
		error_message(INVALID_MLX_INIT);
	map->mlx.win = mlx_new_window(map->mlx.mlx, 1280, 720, "Hello world!");
	mlx_mouse_hide(map->mlx.mlx, map->mlx.win);
	ft_printf("X : %d\n", map->x);
	ft_printf("Y : %d\n", map->y);
	while (i < map->y)
	{
		ft_printf("map[%d] : %s", map->y - i, map->map[i]);
		i++;
	}
	ft_printf("\nCoins : %d\n", map->coins);
	ft_printf("Moves : %d\n", map->moves);
	ft_printf("\n");
	mlx_hook(map->mlx.win, 2, (1L << 0), keypress, map);
	mlx_loop(map->mlx.mlx);
	kill_switch(map);
	return (0);
}
