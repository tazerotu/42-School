/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:24:36 by ttas              #+#    #+#             */
/*   Updated: 2024/08/05 16:22:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

int	init_struct_map(char **argv, t_map *map)
{
	map->fd_map = open(argv[1], O_RDONLY);
	if (!map->fd_map)
		error_message(INVALID_INPUT);
	parsing_map_size(map);
	return (1);
}