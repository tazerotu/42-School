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

SRCS =  ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memmove.c \
		ft_memcpy.c \
		ft_atoi.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_putnbr_fd.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c\
		ft_itoa.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = ${SRCS:.c=.o}

SRCSALL = ${SRCS} ${BONUS}

OBJSALL = ${SRCSALL:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:		${LIB}

bonus: ${OBJSALL}
		ar rcs ${LIB} ${OBJSALL}

%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

${LIB}:	${OBJS}
		ar rcs ${LIB} ${OBJS}

clean:
		@${RM} ${OBJS} ${OBJSALL}

fclean:		clean
		@${RM} ${LIB} ${OBJSALL}

re:			fclean all bonus

.PHONY: all clean fclean re