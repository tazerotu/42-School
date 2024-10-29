/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:54:48 by ttas              #+#    #+#             */
/*   Updated: 2024/10/29 12:06:13 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	init_spite_player(t_map *map, void *dir)
{
	int width;
	int height;
	map->player->img = mlx_xpm_file_to_image(map->mlx.mlx, dir, &width,
			&height);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->player->img,
		(map->player->pos->x * PIX), (map->player->pos->y * PIX));
}