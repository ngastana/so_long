# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 12:49:05 by ngastana          #+#    #+#              #
#    Updated: 2024/03/07 20:13:41 by ngastana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


SRCS = $(shell find "." -name "*.c")

INCLUDE = ./push_swap.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

%.o: %.c
			@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(GREEN)$<"
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS} $(INCLUDE)
	@${CC} ${SRCS} -o ${NAME}
	@echo "\n$(GREEN) Created $(NAME) ✓\n"

clean:
			@${RM} ${OBJS}
			@echo "\n${WHITE} ◎ $(RED)All objects cleaned successfully\n"

fclean: 
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@echo "\n${WHITE} ◎ $(RED)All objects and executable cleaned successfully\n"

re: fclean all

.PHONY: all clean fclean re
