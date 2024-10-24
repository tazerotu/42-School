/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:54:48 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 11:09:19 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	init_spite_player(t_map *map)
{
	int width;
	int height;
	map->player->img = mlx_xpm_file_to_image(map->mlx.mlx, PLAYER_RIGHT, &width,
			&height);
}