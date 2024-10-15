/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:43 by ttas              #+#    #+#             */
/*   Updated: 2024/10/15 12:39:45 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// Valid Return
# define VALID 100
# define VALID_MAP_SIZE 201
# define VALID_MAP_COLLECTIBLES 202
# define VALID_MAP_FLOODFILL 203
# define VALID_MAP_CHAR 204
# define VALID_MAP_CLOSE 205
# define VALID_MAP_PLAYER 206
# define VALID_MAP_EXIT 207
# define HIT 301
# define NO_HIT 302

// Error Handling
# define INVALID -101
# define INVALID_INPUT -102
# define INVALID_MAP_SIZE -201
# define INVALID_MAP_EXIT -202
# define INVALID_MAP_PLAYER -203
# define INVALID_MAP_COLLECTIBLES -204
# define INVALID_MAP_PATH -205
# define INVALID_MAP_CLOSE -206
# define INVALID_MAP_CHAR -207
# define INVALID_MLX_INIT -301

// Jeu
# define PIX 16
# define W 119
# define ARROW_UP 65362
# define A 97
# define ARROW_LEFT 65361
# define S 115
# define ARROW_DOWN 65364
# define D 100
# define ARROW_RIGHT 65363
# define ESC 65307
# define DELAY 30

// Others
# define ERROR_FD 1

// Wall
# define WALL_FACE_TOP
# define WALL_FACE_BOTTOM
# define WALL_FACE_LEFT
# define WALL_FACE_RIGHT
# define WALL_FACE_TOP_LEFT
# define WALL_FACE_TOP_RIGHT
# define WALL_FACE_BOTTOM_LEFT
# define WALL_FACE_BOTTOM_RIGHT
# define WALL_FACE_TOP_BOTTOM
# define WALL_FACE_LEFT_RIGHT
# define WALL_FACE_TOP_LEFT_RIGHT
# define WALL_FACE_TOP_RIGHT_BOTTOM
# define WALL_FACE_TOP_BOTTOM_LEFT
# define WALL_FACE_BOTTOM_LEFT_RIGHT
# define WALL_FACE_ALL
# define WALL_FACE_NONE

// Struct

typedef struct s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct s_queue_node
{
	t_pos				pos;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct s_queue
{
	t_queue_node		*front;
	t_queue_node		*rear;
}						t_queue;

typedef struct s_character
{
	struct s_pos		*pos;
	int					dir;
	int					state;
	void				*img;

}						t_character;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					line_length;
	int					endian;
}						t_mlx;

typedef struct s_map
{
	int					fd_map;
	int					win;
	int					x;
	int					y;
	unsigned int		coins;
	unsigned int		moves;
	t_pos				*exit;
	t_character			*player;
	t_character			*inky;
	t_character			*blinky;
	t_character			*oly;
	char				**map;
	char				**floodfill;
	t_mlx				mlx;
}						t_map;

// INIT
int						init_map(char **argv, t_map *map);
int						init_map_collectibles(t_map *map);
int						init_map_char_player(t_map *map);
int						init_map_char_exit(t_map *map);

// PARSING
int						parsing_map_size(char **argv, t_map *map);
int						parsing_map_init(char **argv, t_map *map);
int						parsing_map_closed(t_map *map);
int						parsing_map_char(t_map *map);
int						parsing_map_char_player(t_map *map);
int						parsing_map_char_exit(t_map *map);

// WALL
void					wall_init(t_map *map, int i, int j);

// ERROR
void					error_message(int error);

// GAME
int						player_win(t_map *map);
void					player_animation(t_map *map);

// MOVE
void					move(t_map *map, int x, int y);
int						keypress(int keycode, t_map *map);
void					kill_switch(t_map *map);
int						bfs(t_pos *start, t_pos *goal, t_map *map);
void					frame_per_second(t_map *map);

// UTILS

#endif
