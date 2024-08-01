/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 11:16:53 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int	main(int argc, char **argv)
{
	t_map **map;
	map = (t_map **)malloc(sizeof(t_map *));
	if (argc != 2)
		return (INVALID_INPUT);
	// parsing_map_size(argv[1], map);
	// printf("%d", map);
	init_struct_map(argv, *map);
	// flood_fill(map);
	free(map);
	return (0);
}