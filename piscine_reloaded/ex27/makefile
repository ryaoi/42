# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 15:13:33 by ryaoi             #+#    #+#              #
#    Updated: 2016/11/06 15:13:34 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_display_file

SRC		= display_file.c

OBJ		= display_file.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

$(OBJ):$(SRC)
	gcc -Wall -Wextra -Werror -o $(OBJ) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
