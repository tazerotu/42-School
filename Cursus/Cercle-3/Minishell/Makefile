# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:28:49 by ttas              #+#    #+#              #
#    Updated: 2025/01/14 09:53:44 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = Minishell

# Files
SRC =			./srcs/main.c \
				

SRCS_INIT =		
				


SRCS_TOKEN =	./srcs/Token/Verify_token.c \
				
				
				

SOURCES =		${SRC} ${SRCS_TOKEN}
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