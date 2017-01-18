# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 14:59:54 by ryaoi             #+#    #+#              #
#    Updated: 2017/01/09 14:16:53 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

DIR_PRI	= ft_printf

PRINTF	= $(DIR_PRI)/libftprintf.a

SRC		= main.c  \
		  ft_no_opt.c  \
		  ft_inspect_file.c   \
		  convert_time.c \
		  check_dir.c \
		  add_list.c \
		  ft_opt_err.c \
		  get_opt.c \
		  init_opt.c \
		  add_file.c \
		  ft_opt_l.c \
		  ft_count.c \
		  print_space.c \
		  print_id.c \
		  print_size.c \
		  swap_file.c \
		  sort_name.c \
		  find_attr.c \
		  sort_reverse.c \
		  add_filedata.c \
		  printfiles.c \
		  dir_permission.c \
		  count_file.c \
		  ft_opt_d.c \
		  swap_list.c \
		  ft_strsub.c \
		  ft_recursion.c \
		  freefile.c \
		  special_case.c \
		  ft_files.c \
		  ft_mode.c

OBJ		= $(SRC:.c=.o)

INCLUDE = -Ift_ls.h \
		  -I./ft_printf/ft_printf.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(PRINTF):
	make -C $(DIR_PRI)

$(NAME): $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) ./ft_printf/libftprintf.a  $(OBJ) $(INCLUDE)

clean:
	make clean -C $(DIR_PRI)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(DIR_PRI)
	rm -rf $(NAME)

re: fclean all
