/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:20:32 by ttas              #+#    #+#             */
/*   Updated: 2024/10/15 12:22:48 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	blinky(t_map *map)
{
	return (0);
}

int	inky(t_map *map)
{
	return (0);
}

int	oly(t_map *map)
{
	return (0);
}

int	collision(t_map *map)
{
	if (map->blinky->pos == map->player->pos)
		return (HIT);
	else if (map->inky->pos == map->player->pos)
		return (HIT);
	else if (map->oly->pos == map->player->pos)
		return (HIT);
	else
		return (NO_HIT);
}