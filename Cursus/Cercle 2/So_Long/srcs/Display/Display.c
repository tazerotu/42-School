/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:10:45 by ttas              #+#    #+#             */
/*   Updated: 2024/10/29 12:06:36 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	wall_draw(t_map *map, char *image, int x, int y)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx.mlx, image, &width, &height);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img, (x * PIX), (y
			* PIX));
	mlx_destroy_image(map->mlx.mlx, img);
	return (0);
}

int	player_draw(t_map *map, char *dir, int x, int y)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx.mlx, dir, &width, &height);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img, (x * PIX), (y
			* PIX));
	mlx_destroy_image(map->mlx.mlx, img);
	return (0);
}

// int	restart(t_map *map)
// {
// 	return (0);
// }
