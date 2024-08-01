/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:24:36 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:54:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

t_map	*init_struct_map(char **argv, t_map *map)
{
	char *buffer;
	buffer = ft_strjoin("./maps/", argv[1]);
	// map = (t_map *)malloc(sizeof(t_map *));
	if (parsing_map_size(buffer, map) == INVALID_MAP_SIZE)
		return (NULL);
	// buffer = parsing_map(fd);
	return (map);
}