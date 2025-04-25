# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 09:38:48 by ttas              #+#    #+#              #
#    Updated: 2024/04/23 09:38:48 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a

SRC_BOOL = 	./bool/ft_isalpha.c \
			./bool/ft_isdigit.c \
			./bool/ft_isascii.c \
			./bool/ft_isprint.c \
			./bool/ft_isalnum.c \
			./bool/ft_tolower.c \
			./bool/ft_toupper.c \
			./bool/ft_isupper.c \

SRC_LST =	./lst/ft_lstnew.c \
			./lst/ft_lstadd_front.c \
			./lst/ft_lstsize.c \
			./lst/ft_lstlast.c \
			./lst/ft_lstadd_back.c \
			./lst/ft_lstclear.c \
			./lst/ft_lstdelone.c \
			./lst/ft_lstiter.c \
			./lst/ft_lstmap.c \

SRC_MEM = 	./mem/ft_memchr.c \
			./mem/ft_memcmp.c \
			./mem/ft_memset.c \
			./mem/ft_bzero.c \
			./mem/ft_memmove.c \
			./mem/ft_memcpy.c \
			./mem/ft_calloc_V2.c \

SRC_PUT =	./put/ft_putchar_fd.c \
			./put/ft_putstr_fd.c \
			./put/ft_putendl_fd.c \
			./put/ft_putnbr_fd.c \

SRC_STR =	./str/ft_strlcat.c \
			./str/ft_strlcpy.c \
			./str/ft_strlen.c \
			./str/ft_strchr.c \
			./str/ft_strrchr.c \
			./str/ft_strdup.c \
			./str/ft_strncmp.c \
			./str/ft_strnstr.c \
			./str/ft_substr.c \
			./str/ft_strjoin.c \
			./str/ft_split.c\
			./str/ft_strtrim_V2.c \
			./str/ft_strmapi.c \
			./str/ft_striteri.c \
			./str/get_next_line_bonus.c \
 
SRC_TO = 	./to/ft_atoi.c \
			./to/ft_itoa.c \
			./to/ft_atol.c \

SRC_PRINTF =	./ft_printf/ft_printf.c	\
				./ft_printf/src/ft_putchar.c	\
				./ft_printf/src/ft_putHexa.c	\
				./ft_printf/src/ft_putnbr.c	\
				./ft_printf/src/ft_putptr.c	\
				./ft_printf/src/ft_putstr.c	\
				./ft_printf/src/ft_putunbr.c	\

SRC_FPRINTF =		./ft_fprintf/ft_fprintf.c	\
					./ft_fprintf/src/ft_putchar.c	\
					./ft_fprintf/src/ft_putHexa.c	\
					./ft_fprintf/src/ft_putnbr.c	\
					./ft_fprintf/src/ft_putptr.c	\
					./ft_fprintf/src/ft_putstr.c	\
					./ft_fprintf/src/ft_putunbr.c	\



# SRC_OTHER = 
SRCSALL = ${SRC_BOOL} ${SRC_LST} ${SRC_MEM} ${SRC_PUT} ${SRC_STR} ${SRC_TO} ${SRC_PRINTF} ${SRC_FPRINTF}

OBJS = ${SRCSALL:.c=.o}

FPRINTF = ./ft_fprintf
PRINTF = ./ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:		${LIB}

%.o:		%.c
		${CC} ${CFLAGS}  -c $? -o $@

${LIB}:	${OBJS}
		ar rcs ${LIB}  ${OBJS}

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${LIB}

re:			fclean all

.PHONY: all clean fclean re