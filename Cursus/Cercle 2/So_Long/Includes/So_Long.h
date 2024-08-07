/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:43 by ttas              #+#    #+#             */
/*   Updated: 2024/08/05 16:22:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Error Handling
# define VALID_MAP_SIZE 2
# define INVALID_INPUT -1
# define INVALID_MAP_SIZE -2
# define INVALID_MAP_EXIT -3
# define INVALID_MAP_PLAYER -4
# define INVALID_MAP_PATH -5

// Jeu
# define PIX 16
# define ESC 0
# define UP 0
# define DOWN 0
# define LEFT 0
# define RIGHT 0

// Others
# define FD 1

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

struct s_pos
{
	int				x;
	int				y;
};

typedef struct s_map
{
	int 			fd_map;
	int				x;
	int				y;
	struct s_pos	*p_start;
	struct s_pos	*exit;
	char 			**map;
}					t_map;

typedef struct s_character
{
	struct s_pos	*pos;

}					t_character;

typedef struct s_path
{
	struct s_pos	*pos;
	struct s_path	*next_pos;
}					t_path;

// INIT
int					init_struct_map(char **argv, t_map *map);
t_map				*init_map(int x, int y, char c, t_map *map);

// PARSING
int					parsing_map_size(t_map *map);

// ERROR
void				error_message(int error);

// UTILS

#endif
