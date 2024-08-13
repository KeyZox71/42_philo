# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 15:08:52 by adjoly            #+#    #+#              #
#    Updated: 2024/08/13 10:42:58 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

NAME  = philo

CC = cc

OBJSDIR = obj/

SRC = ./philo.c \
		./usleep.c \
		./monitor.c \
		./eat.c \
		./parsing.c \
		./log.c \
		./util.c \
		./philo_routine.c \
		./run_philo.c \
		./parsing2.c

I_DIR = ./ 

INCLUDE = -I $(I_DIR)

OBJS = $(addprefix $(OBJSDIR), $(SRC:.c=.o))

FLAGS = -Werror -Wall -Wextra -g

# --------------------------------

all: $(NAME)

$(LIB):
	@make -sj$(nproc) -C $(LIBFT_DIR)

$(NAME): $(LIB) $(OBJS)
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m objects compiled."
	@printf "\n \x1B[1;33m[  ]\x1B[0m compiling $(NAME)..."
	@$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME) -lpthread
	@printf "\x1B[2K\r \x1B[1;33m[  ]\x1B[0m $(NAME) compiled.\n"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) $(FLAGS) $< -c -o $@
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m compiling objects... : $<"

clean:
	@rm -f $(OBJS)
	@printf " \x1B[1;31m[  ]\x1B[0m deleted $(NAME).\n"

fclean: clean
	@rm -f $(NAME)
	@rm -Rf $(OBJSDIR)
	@printf " \x1B[1;31m[  ]\x1B[0m deleted objects.\n"

re: fclean all

.PHONY: clean all re fclean
