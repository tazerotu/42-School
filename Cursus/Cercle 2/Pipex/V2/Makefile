# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 09:56:03 by ttas              #+#    #+#              #
#    Updated: 2024/08/01 12:44:12 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = pipex

# Files
SRC =			main.c

SRCS =			./srcs/Error.c \
				./srcs/Execute.c \
				./srcs/Here_doc.c \
				./srcs/Utils.c

SRCS_UTILS =	./srcs/utils/ft_split.c \
				./srcs/utils/ft_strjoin.c \
				./srcs/utils/ft_strlen.c \
				./srcs/utils/ft_strnstr.c \
				./srcs/utils/ft_strncmp.c \
				./srcs/utils/ft_memcpy.c \
				./srcs/utils/ft_memmove.c \
				./srcs/utils/ft_calloc.c \
				./srcs/utils/get_next_line.c


SOURCES =		${SRC} ${SRCS} ${SRCS_UTILS}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
RM = rm -f

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
FILE_TOTAL	= 9
BAR_SIZE	= ${shell expr 100 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_LOAD	= ${shell expr 23 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_REST	= ${shell expr 23 - ${BAR_LOAD}}

${MAIN_PATH}%.o:%.c .
	@${eval FILE_COUNT = ${shell expr ${FILE_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o}
	@echo " ${RED}-> COMPILATION EN COURS${RESET}${WHITE}[Pipex]${RESET}"
	@printf "${WHITE}[${GREEN}%-.${BAR_LOAD}s${RED}%-.${BAR_REST}s${WHITE}] [%d/%d (%d%%)]${RESET}" "#######################" "#######################" ${FILE_COUNT} ${FILE_TOTAL} ${BAR_SIZE}
	@echo ""
	@echo "${UP}${UP}${UP}"

# Makefile
all:		${EXE}
			@${RM} ${OBJECTS}

${EXE}:		${OBJECTS}  
		@${CC} ${CFLAGS} ${OBJECTS} ${EXE}
		@echo "\n\n\n ${RED}PIPEX EST COMPILÉ 👏${RESET}\n"

ac: all clean

clean:
		@${RM} ${OBJECTS}
		@echo "${ORANGE}\tNETTOYAGE 🛁${RESET}"
		@echo "${DARKBLUE}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean:		clean
		@${RM} ${EXE}
		@echo "${DARKBLUE}${ITALIQUE} -${EXE} est supprimé\n${RESET}"

re:			fclean all

.PHONY: all clean fclean re ac