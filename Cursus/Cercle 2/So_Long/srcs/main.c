/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 12:40:30 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

static void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc == 1 || argv[1][0] == '\0')
		error_message(INVALID_INPUT);
	if (argc > 2)
		error_message(INVALID_INPUT);
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber"))
		error_message(INVALID_INPUT);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		error_message(INVALID_INPUT);
	}
	close(fd);
}

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

// static void	init_struct(t_map *map)
// {
// }

void	kill_switch(t_map *map)
{
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	mlx_destroy_display(map->mlx.mlx);
	free(map->exit);
	free(map->player->pos);
	free(map->player);
	free(map->mlx.mlx);
	free(map);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;
	int		width;
	int		height;

	i = 0;
	check_args(argc, argv);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_message(INVALID);
	map->win = 0;
	map->mlx.mlx = mlx_init();
	if (!map->mlx.mlx)
		error_message(INVALID_MLX_INIT);
	map->mlx.win = mlx_new_window(map->mlx.mlx, 1280, 720, "Hello world!");
	init_malloc(map);
	init_map(argv, map);
	// init_sprite(map);
	map->player->img = mlx_xpm_file_to_image(map->mlx.mlx, PLAYER_RIGHT, &width,
			&height);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->player->img, 540,
		360);
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
	// mlx_loop_hook(map->mlx.mlx, frame_per_second, map);
	mlx_hook(map->mlx.win, 2, (1L << 0), keypress, map);
	mlx_loop(map->mlx.mlx);
	return (0);
}
