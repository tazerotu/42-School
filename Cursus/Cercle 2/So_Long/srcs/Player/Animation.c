/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:16:03 by marvin            #+#    #+#             */
/*   Updated: 2024/09/09 16:16:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	animation(t_map *map)
{
	if(map->player->state == 1 || map->player->state == 5)
	{
		map->player->state++;
		if (map->player->state == 6)
			map->player->state = 1;
	}
	if(map->player->state == 2 || map->player->state == 4)
	{
		map->player->state++;
	}
	if(map->player->state == 3)
	{
		map->player->state++;
	}
}