# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 14:11:33 by ryaoi             #+#    #+#              #
#    Updated: 2016/12/12 12:41:21 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ./ft_printf.c \
		  ./ft_add_prefix.c \
		  ./ft_bzero.c \
		  ./ft_check.c \
		  ./ft_count_digit_base.c \
		  ./ft_hhtoa_base.c \
		  ./ft_htoa_base.c \
		  ./ft_itoa_base.c \
		  ./ft_lltoa_base.c \
		  ./ft_ltoa_base.c \
		  ./ft_memset.c \
		  ./ft_printf_c.c \
		  ./ft_printf_capc.c \
		  ./ft_printf_capd.c \
		  ./ft_printf_capo.c \
		  ./ft_printf_caps.c \
		  ./ft_printf_caps.c \
		  ./ft_printf_capu.c \
		  ./ft_printf_capx.c \
		  ./ft_printf_d.c \
		  ./ft_printf_o.c \
		  ./ft_printf_p.c \
		  ./ft_printf_pourcent.c \
		  ./ft_printf_s.c \
		  ./ft_printf_u.c \
		  ./ft_printf_unicode.c \
		  ./ft_printf_x.c \
		  ./ft_putchar_fd.c \
		  ./ft_putchar.c \
		  ./ft_putstr_fd.c \
		  ./ft_putstr.c \
		  ./ft_str_capitalize.c \
		  ./ft_strdel.c \
		  ./ft_strdup.c \
		  ./ft_strnew.c \
		  ./ft_toupper.c \
		  ./ft_uhhtoa_base.c \
		  ./ft_uhtoa_base.c \
          ./ft_uitoa_base.c \
          ./ft_ulltoa_base.c \
          ./ft_ultoa_base.c \
          ./ft_wcharlen.c \
          ./ft_wstrlen.c \
          ./ft_length_modifer.c \
          ./ft_specifer.c \
		  ./ft_strlen.c \
		  ./ft_strcmp.c \
		  ./ft_strjoin.c \
		  ./ft_isdigit.c \
		  ./ft_memdel.c \
		  ./ft_strcpy.c \
		  ./ft_strcat.c \
		  ./ft_stradjust.c \
		  ./ft_check_hex.c \
		  ./ft_check_oct.c \
		  ./ft_put_space.c \
		  ./ft_check_dec.c \
		  ./ft_init_pf.c \
		  ./ft_only_pourcent.c \
		  ./ft_printf_d_add.c \
		  ./ft_printf_s_add.c \
		  ./ft_add_prefix_add.c

OBJ		= $(SRC:.c=.o)

INCLUDE = ft_printf.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $< 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
