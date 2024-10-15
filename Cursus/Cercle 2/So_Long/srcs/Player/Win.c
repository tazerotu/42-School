/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:05:24 by ttas              #+#    #+#             */
/*   Updated: 2024/10/15 12:27:27 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	player_win(t_map *map)
{
	if (map->coins == 0)
	{
		ft_printf("You win!\n");
		kill_switch(map);
	}
	else
		ft_printf("You need to collect all the coins!\n");
	return (0);
}

int	player_lose(t_map *map)
{
	if (map->win == -1)
		ft_printf("You lost, 'esc' to quit!\n");
	return (0);
}