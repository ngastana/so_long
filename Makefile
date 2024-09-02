# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 15:11:11 by ngastana          #+#    #+#              #
#    Updated: 2024/01/18 12:02:04 by ngastana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# so_long
NAME				=	so_long
NAME_BONUS			=	so_long_bonus

SOLONG_SRC			=	main.c \
                	    arguments_map.c \
                  	  	check_map.c\
                  	 	utils.c \
						map.c \
						movements.c

SOLONG_SRC_BONUS	= $(shell find "." -name "*_bonus.c")

OBJS				= $(SOLONG_SRC:.c=.o)

OBJS_BONUS			= $(SOLONG_SRC_BONUS:.c=.o)

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra
LIBX_FLAGS			=	-Imlx -L./libmlx -lmlx -framework OpenGL -framework AppKit

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# Rules
all:	 $(LIBFT)  $(NAME) 
	@printf "$(BLUE)==> $(CYAN)So_long compiled ✅\n$(RESET)"

$(LIBFT):
	@make -C libft


$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(LIBX_FLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
	@make -C libft fclean 
	@$(RM) $(OBJS) 
	@$(RM) $(OBJS_BONUS)
	@printf "\n$(BLUE)==> $(RED)Removed So_long 🗑️\n$(RESET)"

fclean:		clean
	@$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

bonus:		$(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@${CC} $(CFLAGS) $(LIBX_FLAGS) $(OBJS_BONUS) $(LIBFT_SRC)$(LIBFT) -o $(NAME_BONUS)
	@printf "$(BLUE)==> $(CYAN)so_long_bonus compiled ✅\n$(RESET)"	
	
.PHONY:		all clean fclean re libft
