/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:57:48 by ttas              #+#    #+#             */
/*   Updated: 2024/11/19 11:49:58 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	error_message(int error)
{
	ft_putstr_fd("Error : ", ERROR_FD);
	ft_putnbr_fd(error, ERROR_FD);
	ft_putstr_fd("\n", ERROR_FD);
	exit(1);
}

static void	free_tab(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		free(map->floodfill[i]);
		i++;
	}
	free(map->map);
}

int	kill_switch(t_map *map)
{
	mlx_destroy_image(map->mlx.mlx, map->player->img);
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	mlx_destroy_display(map->mlx.mlx);
	free(map->exit);
	free(map->player->pos);
	free(map->player);
	free(map->mlx.mlx);
	free_tab(map);
	exit(0);
}
