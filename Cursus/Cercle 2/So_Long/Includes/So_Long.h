/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:43 by ttas              #+#    #+#             */
/*   Updated: 2024/11/11 20:38:01 by marvin           ###   ########.fr       */
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
# define VALID_MAP_PATH 208
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
# define PIX 64
# define W 119
# define ARROW_UP 65362
# define A 97
# define ARROW_LEFT 65361
# define S 115
# define ARROW_DOWN 65364
# define D 100
# define ARROW_RIGHT 65363
# define ESC 65307
# define FPS 30

// Others
# define ERROR_FD 1

// Sprite
# define WALL_FACE_TOP "./pacman-art/xpm/walls/wall_I_top.xpm"
# define WALL_FACE_BOTTOM "./pacman-art/xpm/walls/wall_I_down.xpm"
# define WALL_FACE_LEFT "./pacman-art/xpm/walls/wall_I_left.xpm"
# define WALL_FACE_RIGHT "./pacman-art/xpm/walls/wall_I_right.xpm"
# define WALL_FACE_TOP_LEFT "./pacman-art/xpm/walls/wall_L_top_left.xpm"
# define WALL_FACE_TOP_RIGHT "./pacman-art/xpm/walls/wall_L_top_right.xpm"
# define WALL_FACE_BOTTOM_LEFT "./pacman-art/xpm/walls/wall_L_down_left.xpm"
# define WALL_FACE_BOTTOM_RIGHT "./pacman-art/xpm/walls/wall_L_down_right.xpm"
# define WALL_FACE_TOP_BOTTOM "./pacman-art/xpm/walls/wall_horizontal.xpm"
# define WALL_FACE_LEFT_RIGHT "./pacman-art/xpm/walls/wall_vertical.xpm"
# define WALL_FACE_TOP_LEFT_RIGHT "./pacman-art/xpm/walls/wall_U_upper.xpm"
# define WALL_FACE_TOP_RIGHT_BOTTOM "./pacman-art/xpm/walls/wall/U_right.xpm"
# define WALL_FACE_TOP_BOTTOM_LEFT "./pacman-art/xpm/walls/wall_U_left.xpm"
# define WALL_FACE_BOTTOM_LEFT_RIGHT "./pacman-art/xpm/walls/wall_U_down.xpm"

// Player
# define PLAYER_RIGHT "./pacman-art/xpm/pacman-right/1.xpm"
# define PLAYER_LEFT "./pacman-art/xpm/pacman-left/1.xpm"
# define PLAYER_UP "./pacman-art/xpm/pacman-up/1.xpm"
# define PLAYER_DOWN "./pacman-art/xpm/pacman-down/1.xpm"

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
int						floodfill(t_map *map);

// WALL
void					wall_init(t_map *map, int i, int j);
int						wall_draw(t_map *map, char *image, int i, int j);
void					wall_check(t_map *map, int i, int j);
int						overflow(t_map *map, int i, int j);

// ERROR
void					error_message(int error);

// GAME
int						player_win(t_map *map);
void					player_animation(t_map *map);

// MOVE
void					move(t_map *map, int x, int y, void *dir);
int						keypress(int keycode, t_map *map);
void					kill_switch(t_map *map);
int						bfs(t_pos *start, t_pos *goal, t_map *map);
void					frame_per_second(t_map *map);
int						player_draw(t_map *map, char *dir, int x, int y);

// UTILS
void					init_spite_player(t_map *map, void *dir);
void					init_sprite(t_map *map);

#endif
