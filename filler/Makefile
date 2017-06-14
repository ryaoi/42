# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 23:09:46 by ryaoi             #+#    #+#              #
#    Updated: 2017/05/10 01:37:48 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ryaoi.filler

DIR_LIB	= libft

LIBFT	= $(DIR_LIB)/libft.a

SRC		= main.c \
		  ft_maps.c \
		  freetab.c \
		  first_move.c \
		  ft_check.c \
		  ft_direction1.c \
		  ft_odirections.c \
		  ft_checko.c \
		  ft_readmap.c \
		  ft_player.c \
		  ft_strat_up.c \
		  ft_strat_down.c \
		  ft_direction2.c \
		  ft_direction3.c

OBJ		= $(SRC:.c=.o)

INCLUDE	= -Ifiller.h \
		  -I./libft/libft.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) -I./$(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C $(DIR_LIB)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) ./libft/libft.a $(OBJ) $(INCLUDE) -ltermcap

clean:
	make clean -C $(DIR_LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re: fclean all
