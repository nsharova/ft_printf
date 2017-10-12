#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsharova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 00:30:07 by nsharova          #+#    #+#              #
#    Updated: 2017/10/12 23:02:21 by nsharova         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror -c

SRC = ft_check_format.c \
		ft_get_arg.c \
		ft_get_format.c \
		ft_itoa_base.c \
		ft_print_arg.c \
		ft_print_wchar.c \
		ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(SRC)
	ar rc $(NAME) libft/*.o $(OBJ)

clean:
	make fclean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all