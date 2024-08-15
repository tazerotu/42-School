/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/08/15 10:48:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int	main(int argc, char **argv)
{
	if(argc != 2)
		error_message(INVALID_INPUT);
	t_map *map;
	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
		error_message(INVALID);
	init_struct(argv, map);
	printf("X : %d\n", map->x);
	printf("Y : %d\n", map->y);
	for(unsigned int i = 0; i < map->y; i++)
		printf("map[%d] : %s", i, map->map[i]);
	printf("\n");
	free(map->exit);
	free(map->p_start);
	free(map->map);
	free(map);
	return (0);
}