# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 10:49:44 by ttas              #+#    #+#              #
#    Updated: 2024/10/24 09:24:17 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libftfdprintf.a

SRCS =  ft_fdprintf.c \
		./src/ft_putstr.c \
		./src/ft_putchar.c \
		./src/ft_putnbr.c \
		./src/ft_putHexa.c \
		./src/ft_putunbr.c \
		./src/ft_putptr.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:		${LIB}

%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

${LIB}:	${OBJS}
		ar rcs ${LIB} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${LIB}

re:			fclean all

.PHONY: all clean fclean re