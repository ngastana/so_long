# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 17:15:05 by ngastana          #+#    #+#              #
#    Updated: 2023/10/05 21:02:44 by ngastana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(shell find "." -name "*.c")
			
OBJS = ${SRCS:.c=.o}

CC      = gcc
RM      = rm -rf
CFLAGS  = -c -Wall -Wextra -Werror
AR      = ar csr

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): %.o : %.c
	${CC} $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus