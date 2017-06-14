# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:54:47 by ryaoi             #+#    #+#              #
#    Updated: 2017/05/09 09:41:04 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= filler_visu

DIR_LIBFT	= ../libft

LIBFT		= $(DIR_LIBFT)/libft.a

SRC			= main.c \
			  print_elem.c \
			  ft_pages.c \
			  ft_design.c \
			  e_mlx.c \
			  r_mlx.c

OBJ			= $(SRC:.c=.o)

INCLUDE		= -Ifiller_visu.h \
			  -I../libft/libft.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C $(DIR_LIBFT)

$(NAME): $(LIBFT) $(OBJ)
	    $(CC) $(CFLAGS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o filler_visu $(OBJ) $(INCLUDE) ../libft/libft.a

clean:
	    make clean -C $(DIR_LIBFT)
		    rm -rf $(OBJ)

fclean: clean
	    make fclean -C $(DIR_LIBFT)
		    rm -rf $(NAME)

re: fclean all
