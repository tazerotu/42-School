/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/08/05 16:30:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int	main(int argc, char **argv)
{
	t_map *map;
	map = (t_map *)malloc(sizeof(t_map));
	if (argc != 2)
		return (INVALID_INPUT);
	// parsing_map_size(argv[1], map);
	init_struct_map(argv, map);
	printf("X : %d\n", map->x);
	printf("Y : %d\n", map->y);
	// flood_fill(map);
	free(map);
	return (0);
}