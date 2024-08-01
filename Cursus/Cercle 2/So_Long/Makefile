# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 09:21:00 by ttas              #+#    #+#              #
#    Updated: 2024/08/01 12:09:33 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = So_Long

# Files
SRC =			./srcs/main.c

SRCS =			

SRCS_PARSING = 	./srcs/Parsing/Parsing_Map.c \
				


SRCS_INIT =		./srcs/Init/Init_Struct.c \
				./srcs/Init/Init_Map.c \
				
SRCS_UTILS = 	./srcs/utils/Error.c

GNL = 			./Includes/gnl/get_next_line.c\

SOURCES =		${SRC} ${SRCS_PARSING} ${SRCS_INIT} ${SRCS_UTILS} ${GNL}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
# 
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
RM = rm -f
LIBFT = ./Includes/libft

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
FILE_TOTAL	= 6
BAR_SIZE	= ${shell expr 100 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_LOAD	= ${shell expr 23 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_REST	= ${shell expr 23 - ${BAR_LOAD}}

${MAIN_PATH}%.o:%.c .
	@${eval FILE_COUNT = ${shell expr ${FILE_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o}
	@echo " ${RED}-> COMPILATION EN COURS${RESET}${WHITE}[So Long]${RESET}"
	@printf "${WHITE}[${GREEN}%-.${BAR_LOAD}s${RED}%-.${BAR_REST}s${WHITE}] [%d/%d (%d%%)]${RESET}" "#######################" "#######################" ${FILE_COUNT} ${FILE_TOTAL} ${BAR_SIZE}
	@echo ""
	@echo "${UP}${UP}${UP}"

# Makefile
all:		${EXE}
			@${RM} ${OBJECTS}
			@${MAKE}  --silent -C ${LIBFT} clean

${EXE}:		${OBJECTS} 
		@${MAKE} --silent -C ${LIBFT} 
		@${CC} ${CFLAGS} ${OBJECTS} ./Includes/libft/libft.a -o ${EXE}
		@echo "\n\n\n ${RED}SO LONG EST COMPILÉ 👏${RESET}\n"

ac: all clean

clean:
		@${RM} ${OBJECTS}
		@${MAKE} --silent -C ${LIBFT} clean
		@echo "${ORANGE}\tNETTOYAGE 🛁${RESET}"
		@echo "${DARKBLUE}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean:		clean
		@${RM} ${EXE}
		@${MAKE} --silent -C ${LIBFT} fclean
		@echo "${DARKBLUE}${ITALIQUE} -${EXE} est supprimé\n${RESET}"

re:			fclean all

.PHONY: all clean fclean re ac