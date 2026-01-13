# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 19:48:54 by emaigne           #+#    #+#              #
#    Updated: 2026/01/09 22:43:52 by emaigne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_A =$(SRC_A:.c=.o)

SRC_A	= ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_striteri.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c

SRC_DIR = .
NAME = libft.a
CC = cc
AR = ar
FLAGS = -Wall -Wextra -Werror
HEADER_FILE = libft.h

all: $(NAME)

$(NAME): $(OBJS_A)
	$(AR) -rcs $(NAME) $(OBJS_A)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@	

clean:
	rm -f $(OBJS_A)	

fclean: clean
	rm -f $(NAME)	

re: fclean all

.PHONY: all clean fclean re

#cc *.c -Llibft -lft -Ilibft -Lft_printf -lftprintf -Ift_printf
#to compile
