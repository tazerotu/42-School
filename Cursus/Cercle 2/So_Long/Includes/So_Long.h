/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:43 by ttas              #+#    #+#             */
/*   Updated: 2024/07/01 09:47:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PIX 16
# define ESC 0
# define UP 0
# define DOWN 0
# define LEFT 0
# define RIGHT 0

typedef struct s_map
{
	int				x;
	int				y;
	struct s_pos	p_start;
	struct s_pos	exit;
}					t_map;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_character
{
	struct s_pos	*pos;

}					t_character;

#endif
