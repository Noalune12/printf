# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 08:33:31 by lbuisson          #+#    #+#              #
#    Updated: 2024/11/20 08:25:42 by lbuisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

RM = rm -f

SRCS = ft_printf.c ft_numbers.c ft_words_pointer.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft

LIBFT_A = $(LIBFT_DIR)/libft.a

all : $(LIBFT_A) $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_A) $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all fclean clean re
