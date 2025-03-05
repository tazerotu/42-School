# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:28:49 by ttas              #+#    #+#              #
#    Updated: 2025/03/05 12:42:40 by clai-ton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
PARSE = parse.exe

# Files

PARSE_SOURCES = ./srcs/main_parser.c \
				./srcs/lexer/incorrect_quotes.c \
				./srcs/lexer/replace_variable.c \
				./srcs/lexer/trim_token.c \
				./srcs/lexer/tokenizer_1.c

PARSE_OBJECTS =	${PARSE_SOURCES:.c=.o}
LIBFT = ./Includes/libft

# Variables
CC = cc
RM = rm -f
# 
CFLAGS = -Wall -Werror -Wextra -Includes
CLEAKS = -fsanitize=address -g 

# Makefile
%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

all:		${PARSE}

${PARSE}:		${PARSE_OBJECTS}
		@${MAKE} --silent -C ${LIBFT}
		@${CC} ${CFLAGS} ${CLEAKS} ${PARSE_OBJECTS} ./Includes/libft/libft.a -lreadline -o $@

ac: all clean

clean:
		@${MAKE} --silent -C ${LIBFT} clean
		@${RM} ${PARSE_OBJECTS}

fclean:		clean
		@${MAKE} --silent -C ${LIBFT} fclean
		@${RM} ${PARSE}

re:			fclean all

.PHONY: all clean fclean re ac