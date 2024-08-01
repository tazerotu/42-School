/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:41 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:58:50 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int	main(int argc, char **argv)
{
	t_map **map;
	map = NULL;
	if (argc != 2)
		return (INVALID_INPUT);
	// parsing_map_size(argv[1], map);
	// printf("%d", map);
	init_struct_map(argv, *map);
	// printf("%d\n", (*map)->exit->x);
	// printf("%d\n", (*map)->exit->y);
	// printf("%d\n", (*map)->p_start->x);
	// printf("%d\n", (*map)->p_start->y);
	// printf("%d\n", (*map)->x);
	// printf("%d\n", (*map)->y);
	// flood_fill(map);
	return (0);
}