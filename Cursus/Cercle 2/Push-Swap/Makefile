# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 09:56:03 by ttas              #+#    #+#              #
#    Updated: 2024/06/26 10:30:19 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = push_swap

# Files
SRC =			main.c

SRC_PARSING =	./srcs/utils/verification.c \
				./srcs/utils/display.c \

SRC_UTILS =		./srcs/utils/ft_lst.c \
				./srcs/utils/ft_to.c \
				./srcs/utils/ft_str.c \
				./srcs/utils/ft_split.c \
				./srcs/utils/movements_utils.c \
				./srcs/utils/other_utils.c \

SRC_MOVES =		./srcs/movements/push.c \
				./srcs/movements/swap.c \
				./srcs/movements/rotate.c \
				./srcs/movements/reverse_rotate.c \

SRC_SORT =		./srcs/sort/simple_sort.c \
				./srcs/sort/is_sorted.c \
				./srcs/sort/radix_sort.c \


SOURCES =		${SRC} ${SRC_PARSING} ${SRC_UTILS} ${SRC_MOVES} ${SRC_SORT}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
RM = rm -f
FT_PRINTF = ./includes/ft_printf

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

WHITE		= \e[0;97m
GOLD = \033[38;5;220m
CYAN = \033[38;5;51m
ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;196m
GREEN = \033[38;5;46m

NBR_COMPILER = ${shell expr 100 \* ${FILE_COUNT} / ${FILE_TOTAL}}
FILE_COUNT	= 0
FILE_TOTAL	= 16
BAR_SIZE	= ${shell expr 100 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_LOAD	= ${shell expr 23 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_REST	= ${shell expr 23 - ${BAR_LOAD}}

${MAIN_PATH}%.o:%.c .
	@${eval FILE_COUNT = ${shell expr ${FILE_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o}
	@echo " ${RED}-> COMPILATION EN COURS${RESET}${WHITE}[Push Swap]${RESET}"
	@printf "${WHITE}[${GREEN}%-.${BAR_LOAD}s${RED}%-.${BAR_REST}s${WHITE}] [%d/%d (%d%%)]${RESET}" "#######################" "#######################" ${FILE_COUNT} ${FILE_TOTAL} ${BAR_SIZE}
	@echo ""
	@echo "${UP}${UP}${UP}"

# Makefile
all:		${EXE}
			@${RM} ${OBJECTS}
			@${MAKE}  --silent -C ./includes/ft_printf clean

${EXE}:		${OBJECTS} 
		@${MAKE} --silent -C ./includes/ft_printf 
		@${CC} ${CFLAGS} ${OBJECTS} ./includes/ft_printf/libftprintf.a -o ${EXE}
		@echo "\n\n\n ${RED}PUSH SWAP EST COMPILÉ 👏${RESET}\n"

ac: all clean

clean:
		@${RM} ${OBJECTS}
		@${MAKE} --silent -C ./includes/ft_printf clean
		@echo "${ORANGE}\tNETTOYAGE 🛁${RESET}"
		@echo "${DARKBLUE}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean:		clean
		@${RM} ${EXE}
		@${MAKE} --silent -C ./includes/ft_printf fclean
		@echo "${DARKBLUE}${ITALIQUE} -${EXE} est supprimé\n${RESET}"

re:			fclean all

.PHONY: all clean fclean re ac