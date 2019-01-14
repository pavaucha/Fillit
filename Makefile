# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 11:53:21 by pavaucha          #+#    #+#              #
#    Updated: 2017/11/29 14:45:27 by lezhang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

INC = fillit.h

LIB = libft/libft.a

SRC = ft_fillit_in.c	\
	  ft_strfree.c		\
	  ft_verif_termi.c	\
	  ft_read_file.c	\
	  ft_strnew_c.c		\
	  ft_check_around.c	\
	  ft_stock_termi.c	\
	  ft_verif_form.c	\
	  ft_function.c		\
	  ft_error_file.c	\
	  main.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@ $(CC) $(FLAGS) -c $(SRC)
	@ cd libft; make
	@ $(CC) $(FLAGS) $(SRCO) $(LIB) -o $(NAME)

clean:
	@ rm -f $(SRCO)
	@ cd libft; make clean

fclean: clean
	@ rm -f $(NAME)
	@ cd libft; make fclean

re: fclean all
	@ cd libft; make re

.PHONY: all clean fclean re
