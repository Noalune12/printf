# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuisson <lbuisson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 08:33:31 by lbuisson          #+#    #+#              #
#    Updated: 2024/11/20 13:39:22 by lbuisson         ###   ########.fr        #
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

LIBFT_FUNCTIONS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_striteri.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c \
	ft_strtrim.c ft_tolower.c ft_toupper.c

LIBFT_FILES = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FUNCTIONS)) $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/Makefile

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_FILES)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_A) $(NAME)
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
