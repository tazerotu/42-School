/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:05:24 by ttas              #+#    #+#             */
/*   Updated: 2024/10/02 12:09:04 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	player_win(t_map *map)
{
	if (map->coins == 0)
	{
		printf("You win!\n");
		exit(0);
	}
	else
		printf("You need to collect all the coins!\n");
	return (0);
}
