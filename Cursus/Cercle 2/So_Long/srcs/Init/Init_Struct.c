/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:24:36 by ttas              #+#    #+#             */
/*   Updated: 2024/07/25 10:28:11 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	init_struct(char **argv)
{
	char *buffer;
	buffer = ft_strjoin("./maps/", argv[1]);
	if (parsing_map(buffer) == INVALID_MAP_SIZE)
		return ;
	// buffer = parsing_map(fd);
}