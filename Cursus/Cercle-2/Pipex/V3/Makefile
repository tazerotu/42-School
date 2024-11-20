# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 09:56:03 by ttas              #+#    #+#              #
#    Updated: 2024/10/22 10:53:49 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = pipex

# Files
SRC =			./srcs/main.c \
				./srcs/utils.c		

SOURCES =		${SRC}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
# 
CFLAGS = -Wall -Werror -Wextra -Includes -fsanitize=address -g
RM = rm -f

# Libraries
LIBFT = ./Include/libft

# Makefile
%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

all:		${EXE}

${EXE}:		${OBJECTS} 
		@${MAKE} --silent -C ${LIBFT}
		@${CC} ${CFLAGS} ${OBJECTS} ./Include/libft/libft.a -o ${EXE}

ac: all clean

clean:
		@${RM} ${OBJECTS}
		@${MAKE} --silent -C ${LIBFT} clean

fclean:		clean
		@${RM} ${EXE}
		@${MAKE} --silent -C ${LIBFT} fclean

re:			fclean all

.PHONY: all clean fclean re ac