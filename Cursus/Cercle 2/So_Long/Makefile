# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 09:21:00 by ttas              #+#    #+#              #
#    Updated: 2024/10/24 10:05:28 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = So_Long

# Files
SRC =			./srcs/main.c		

SRCS_MAP = 		./srcs/Map/Init_Map.c \
				./srcs/Map/Parsing_Map.c \
				./srcs/Map/Parsing_Map_Char.c \
				./srcs/Player/Moves.c \
				./srcs/Player/Win.c \
				./srcs/Player/FPS.c \
				./srcs/Player/Animation.c \
				./srcs/Pathfinding/Path.c \
				./srcs/Map/FloodFill.c \
				./srcs/Display/Display.c \
				./srcs/Map/wall.c

SRCS_PLAYER = 	

SRCS_UTILS = 	./srcs/utils/Error.c

GNL = 			./Includes/gnl/get_next_line.c\
#				./Includes/gnl/get_next_line_utils.c\

SOURCES =		${SRC} ${SRCS_MAP} ${SRCS_UTILS} ${GNL}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
# 
CFLAGS = -Wall -Werror -Wextra -Includes -fsanitize=address -g
RM = rm -f

# Libraries
MINILIBX	=	./minilibx-linux
LIBFT = ./Includes/libft
PRINTF = ./Includes/ft_printf

# Makefile
%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

all:		${EXE}

${EXE}:		${OBJECTS} 
		@${MAKE} --silent -C ${LIBFT}
		@${MAKE} --silent -C ./Includes/ft_printf
		@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
		@${CC} ${CFLAGS} ${OBJECTS} ./Includes/ft_printf/libftprintf.a ./Includes/libft/libft.a -L${MINILIBX} -lmlx -lX11 -lXext -o ${EXE}

ac: all clean

clean:
		@${RM} ${OBJECTS}
		@${MAKE} --silent -C ${LIBFT} clean
		@${MAKE} --silent -C ./Includes/ft_printf clean

fclean:		clean
		@${RM} ${EXE}
		@${MAKE} --silent -C ${LIBFT} fclean
		@${MAKE} --silent -C ./Includes/ft_printf fclean

re:			fclean all

.PHONY: all clean fclean re ac