# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:28:49 by ttas              #+#    #+#              #
#    Updated: 2025/03/11 12:26:32 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = Executor

# Files
SRC =			./srcs/main.c 

SRCS_INIT =		./srcs/init/init.c \
				./srcs/free/free.c \
	
SRCS_PIPEX =	

SRCS_BUILT_IN =	./srcs/pipex/built_in/env.c \
				./srcs/pipex/built_in/bi_utils/env_utils.c \
				./srcs/pipex/built_in/pwd.c \
				./srcs/pipex/built_in/unset.c \
				./srcs/pipex/built_in/cd.c \
				./srcs/pipex/built_in/export.c \
				./srcs/pipex/built_in/echo.c \

SRCS_UTILS =	./srcs/utils/error.c \
				
								
				

SOURCES =		${SRC} ${SRCS_INIT} ${SRCS_BUILT_IN} ${SRCS_UTILS}
OBJECTS =		${SOURCES:.c=.o}
LIBFT = ./includes/libft

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
		@${CC} ${CFLAGS} ${OBJECTS} ./includes/libft/libft.a -lreadline -o ${EXE}

ac: all clean

clean:
		@${MAKE} --silent -C ${LIBFT} clean
		@${RM} ${OBJECTS}

fclean:		clean
		@${MAKE} --silent -C ${LIBFT} fclean
		@${RM} ${EXE}

re:			fclean all

.PHONY: all clean fclean re ac