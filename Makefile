# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 12:02:58 by lleiria-          #+#    #+#              #
#    Updated: 2022/02/07 16:53:18 by lleiria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

SRC = 	ft_putchar.c				\
		ft_putstr.c					\
		ft_putnbr.c					\
		ft_putpoint.c				\
		ft_putnbr_base.c			\
		ft_putun.c					\
		ft_printf.c					\
		

OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all