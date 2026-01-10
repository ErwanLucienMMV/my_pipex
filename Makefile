OBJS =$(SRC:.c=.o)

SRC = pipex_utils.c \
find_command.c \
pipex.c 

NAME = pipex
SRC_DIR = .
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER_FILE = pipex.h
PATH_FT_PRINTF = ./ft_printf
PATH_LIBFT = ./libft
LIBFT_A = ./libft/libft.a
FT_PRINTF_A = ./ft_printf/libftprintf.a

all: $(NAME)

ft_printf:
		make -C $(PATH_FT_PRINTF)

libft:
		make -C $(PATH_LIBFT)

$(NAME): $(OBJS) | libft ft_printf 
		$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) $(FT_PRINTF_A) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		make -C $(PATH_FT_PRINTF) clean
		make -C $(PATH_LIBFT) clean

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT_A)
		rm -f $(FT_PRINTF_A)

re: fclean all

.PHONY: all clean fclean re libft ft_printf
