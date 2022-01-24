# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 12:02:58 by lleiria-          #+#    #+#              #
#    Updated: 2022/01/24 12:03:01 by lleiria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

SRC = 	Libft/ft_strlen.c				\
		Libft/ft_itoa_base.c			\
		ft_putescapes.c 				\
		ft_printf.c						\
		ft_putvar.c						\
		ft_putchar.c					\
		ft_putstr.c						\
		ft_putunnumbers.c				\
		ft_putnumbers.c					\
		ft_hexnumbers.c					\
		ft_putaddr.c					\
		

OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all