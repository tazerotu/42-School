/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:05:48 by ttas              #+#    #+#             */
/*   Updated: 2024/11/19 09:51:01 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	init_spite_player(t_map *map, void *dir)
{
	int	width;
	int	height;

	map->player->img = mlx_xpm_file_to_image(map->mlx.mlx, dir, &width,
			&height);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->player->img,
		(map->player->pos->x * PIX), (map->player->pos->y * PIX));
}

void	coin_init(t_map *map)
{
	int		width;
	int		height;
	void	*img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->map[i][j] == 'C')
			{
				img = mlx_xpm_file_to_image(map->mlx.mlx, COIN, &width,
						&height);
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img,
					(j * PIX), (i * PIX));
				mlx_destroy_image(map->mlx.mlx, img);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	exit_init(t_map *map)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx.mlx, EXIT, &width, &height);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img,
		(map->exit->x * PIX), (map->exit->y * PIX));
	mlx_destroy_image(map->mlx.mlx, img);
}

void	init_sprite(t_map *map)
{
	wall_check(map);
	exit_init(map);
	init_spite_player(map, PLAYER_RIGHT);
	coin_init(map);
}
