/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:24:36 by ttas              #+#    #+#             */
/*   Updated: 2024/08/13 10:51:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	init_map(char **argv, t_map *map)
{
	parsing_map_size(argv, map);
	parsing_map_init(argv, map);
	parsing_map_collectibles(map);
	return (1);
}