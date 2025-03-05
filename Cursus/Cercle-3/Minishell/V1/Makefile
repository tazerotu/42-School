# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:28:49 by ttas              #+#    #+#              #
#    Updated: 2025/03/05 12:02:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = Executor

# Files
SRC =			./srcs/main.c 

SRCS_INIT =		./srcs/Init/Init.c \
				./srcs/free/free.c \
	
SRCS_PIPEX =	

SRCS_BUILT_IN =	./srcs/Pipex/Built-in/env.c \
				./srcs/Pipex/Built-in/bi_utils/env_utils.c \
				./srcs/Pipex/Built-in/pwd.c \
				./srcs/Pipex/Built-in/unset.c \
								
				

SOURCES =		${SRC} ${SRCS_INIT} ${SRCS_BUILT_IN}
OBJECTS =		${SOURCES:.c=.o}
LIBFT = ./Includes/libft

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
		@${MAKE} --silent -C ${LIBFT}
		@${CC} ${CFLAGS} ${OBJECTS} ./Includes/libft/libft.a -lreadline -o ${EXE}

ac: all clean

clean:
		@${MAKE} --silent -C ${LIBFT} clean
		@${RM} ${OBJECTS}

fclean:		clean
		@${MAKE} --silent -C ${LIBFT} fclean
		@${RM} ${EXE}

re:			fclean all

.PHONY: all clean fclean re ac