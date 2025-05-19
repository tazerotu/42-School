# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 09:50:03 by ttas              #+#    #+#              #
#    Updated: 2025/05/19 11:27:25 by clai-ton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = Minishell

# Files
SRC =				./src/main.c

SRC_EXECUTION =		./common/execution/srcs/init/init.c \
					./common/execution/srcs/free/free.c \
					./common/execution/srcs/pipex/pipex.c \
					./common/execution/srcs/pipex/pipex_utils/here_doc.c \
					./common/execution/srcs/pipex/pipex_utils/redirection.c \
					./common/execution/srcs/pipex/pipex_utils/pipex_utils.c \
					./common/execution/srcs/pipex/built_in/env.c \
					./common/execution/srcs/pipex/built_in/bi_utils/env_utils.c \
					./common/execution/srcs/pipex/built_in/pwd.c \
					./common/execution/srcs/pipex/built_in/unset.c \
					./common/execution/srcs/pipex/built_in/cd.c \
					./common/execution/srcs/pipex/built_in/export.c \
					./common/execution/srcs/pipex/built_in/echo.c \
					./common/execution/srcs/pipex/built_in/exit.c \
					./common/execution/srcs/pipex/built_in/verify_built_in.c \
					./common/execution/srcs/utils/error.c \
					# ./common/execution/srcs/execution.c \
					# ./common/execution/srcs/pipex/pipex_utils/get_env.c \
					# ./common/execution/srcs/pipex/pipex_utils/expander.c \
					# ./common/execution/srcs/pipex/pipex_utils/expander_utils.c \

					
SRC_PARSER =		./common/parser/srcs/main_parser.c \
					./common/parser/srcs/env/get_env.c \
					./common/parser/srcs/free/free.c \
					./common/parser/srcs/free/free_cmds.c \
					./common/parser/srcs/init/init.c \
					./common/parser/srcs/utils/error.c \
					./common/parser/srcs/parser/parser_utils.c \
					./common/parser/srcs/parser/parser.c \
					./common/parser/srcs/parser/commands/cmd_create.c \
					./common/parser/srcs/parser/commands/cmd_fill.c \
					./common/parser/srcs/parser/expander/expand_tok_rm_quote.c \
					./common/parser/srcs/parser/expander/expand_tok.c \
					./common/parser/srcs/parser/expander/expander_utils.c \
					./common/parser/srcs/parser/expander/expander_utils2.c \
					./common/parser/srcs/parser/expander/expander.c \
					./common/parser/srcs/parser/split_prompt/split_prompt.c \
					./common/parser/srcs/parser/split_prompt/split_special.c \
					./common/parser/srcs/parser/syntax_check/verify_pipe.c \
					./common/parser/srcs/parser/syntax_check/verify_quotes.c \
					./common/parser/srcs/parser/syntax_check/verify_words.c \
					# ./common/parser/srcs/env/env_utils.c \
					


SOURCES =		${SRC} ${SRC_EXECUTION} ${SRC_PARSER}
OBJECTS =		${SOURCES:.c=.o}
LIBFT = ./common/libft

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
		@${CC} ${CFLAGS} ${OBJECTS} ${LIBFT}/libft.a -lreadline -o ${EXE}
ac: all clean

clean:
		@${MAKE} --silent -C ${LIBFT} clean
		@${RM} ${OBJECTS}

fclean:		clean
		@${MAKE} --silent -C ${LIBFT} fclean
		@${RM} ${EXE}

re:			fclean all

.PHONY: all clean fclean re ac