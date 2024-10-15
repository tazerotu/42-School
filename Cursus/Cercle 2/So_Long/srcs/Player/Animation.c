/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:05:52 by ttas              #+#    #+#             */
/*   Updated: 2024/10/15 10:15:51 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	player_animation(t_map *map)
{
	if (map->player->state == 1 || map->player->state == 5)
	{
		map->player->state++;
		if (map->player->state == 6)
			map->player->state = 1;
	}
	if (map->player->state == 2 || map->player->state == 4)
	{
		map->player->state++;
	}
	if (map->player->state == 3)
	{
		map->player->state++;
	}
}
