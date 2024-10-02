# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 09:21:00 by ttas              #+#    #+#              #
#    Updated: 2024/10/01 15:08:11 by marvin           ###   ########.fr        #
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
#				./srcs/Map/FloodFill.c \

SRCS_PLAYER = 	

SRCS_UTILS = 	./srcs/utils/Error.c

GNL = 			./Includes/gnl/get_next_line.c\

SOURCES =		${SRC} ${SRCS_MAP} ${SRCS_UTILS} ${GNL}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
# 
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
RM = rm -f

# Libraries
MINILIBX	=	./minilibx-linux
LIBFT = ./Includes/libft

# Makefile
all:		${EXE}
		@${RM} ${OBJECTS}
		@${MAKE}  --silent -C ${LIBFT} clean 

${EXE}:		${OBJECTS} 
		@${MAKE} --silent -C ${LIBFT}
		@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
		@${CC} ${CFLAGS} ${OBJECTS} ./Includes/libft/libft.a -L${MINILIBX} -lmlx -lX11 -lXext -lm -o ${EXE}

ac: all clean

clean:
		@${RM} ${OBJECTS}
		@${MAKE} --silent -C ${LIBFT} clean

fclean:		clean
		@${RM} ${EXE}
		@${MAKE} --silent -C ${LIBFT} fclean

re:			fclean all

.PHONY: all clean fclean re ac