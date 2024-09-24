/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:43:10 by ttas              #+#    #+#             */
/*   Updated: 2024/08/13 17:36:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int player_win(t_map *map)
{
	if(map->player->pos->x == map->exit->x && map->player->pos->y == map->exit->y)
	{
		if(map->coins == 0)
		{
			ft_printf("You win!\n");
			exit(0);
		}
		else
		{
			ft_printf("You need to collect all the coins!\n");
		}
	}
}