/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FPS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:44:32 by ttas              #+#    #+#             */
/*   Updated: 2024/10/14 15:33:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void frame_per_second(t_map *map)
{
	static int		fps = 0;
	static int		frames = 0;
	static time_t	last_time = 0;
	time_t			current_time;

	current_time = time(NULL);
	if (current_time != last_time)
	{
		last_time = current_time;
		fps = frames;
		frames = 0;
		// Update NPC animation and enemy moves
		player_animation(map);
		ghost_moves(map);
	}
	mlx_string_put(map->mlx.mlx, map->mlx.win, 10, 10, 0x00FFFFFF, "FPS: ");
	mlx_string_put(map->mlx.mlx, map->mlx.win, 50, 10, 0x00FFFFFF, ft_itoa(fps));
	frames++;
}