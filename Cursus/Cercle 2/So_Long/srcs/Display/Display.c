/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:10:45 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 10:21:58 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	wall_draw(t_map *map, void *image)
{
	int	width;
	int	height;

	mlx_xpm_file_to_image(map->mlx.mlx, &image, &width, &height);
}

// int	restart(t_map *map)
// {
// 	return (0);
// }
