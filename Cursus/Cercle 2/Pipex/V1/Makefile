# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 09:56:03 by ttas              #+#    #+#              #
#    Updated: 2024/11/05 09:55:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = pipex

# Files
SRC =			./srcs/pipex.c \
				./srcs/utils.c \

SRC_UTILS =		./srcs/ft_utils/ft_split.c \
				./srcs/ft_utils/ft_strjoin.c \
				./srcs/ft_utils/ft_strlen.c \
				./srcs/ft_utils/ft_strnstr.c \
				./srcs/ft_utils/ft_putstr_fd.c \
				./srcs/ft_utils/ft_strncmp.c \

SOURCES =		${SRC} ${SRC_UTILS}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
# 
CFLAGS = -Wall -Werror -Wextra -Includes -fsanitize=address -g
RM = rm -f

# Makefile
%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

all:		${EXE}

${EXE}:		${OBJECTS} 
		@${CC} ${CFLAGS} ${OBJECTS} -o ${EXE}

ac: all clean

clean:
		@${RM} ${OBJECTS}

fclean:		clean
		@${RM} ${EXE}

re:			fclean all

.PHONY: all clean fclean re ac