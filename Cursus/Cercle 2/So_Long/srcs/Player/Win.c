/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:05:24 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 09:05:25 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	player_win(t_map *map)
{
	if (map->player->pos->x == map->exit->x
		&& map->player->pos->y == map->exit->y)
	{
		if (map->coins == 0)
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
