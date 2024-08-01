/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:44:24 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:49:11 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

t_map	*init_map(int x, int y, char c, t_map *map)
{
	if (c == 'S')
	{
		map->x = x;
		map->y = y;
	}
	else if (c == 'P')
	{
		map->p_start->x = x;
		map->p_start->y = y;
	}
	else if (c == 'E')
	{
		map->exit->x = x;
		map->exit->y = y;
	}
	return (map);
}