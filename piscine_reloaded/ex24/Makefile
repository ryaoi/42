# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 15:12:47 by ryaoi             #+#    #+#              #
#    Updated: 2016/11/06 15:12:48 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ./srcs/ft_putchar.c \
		  ./srcs/ft_putstr.c  \
		  ./srcs/ft_strcmp.c  \
		  ./srcs/ft_strlen.c  \
		  ./srcs/ft_swap.c

INCLUDE	= /includes/

OBJ		= $(SRC:.c=.o)

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c 
	$(CC) $(FLAGS) -o $@ -c $< -I$(INCLUDE)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
