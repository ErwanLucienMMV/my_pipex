OBJS =$(SRC:.c=.o)

SRC = pipex_utils.C \
find_command.c \
pipex.c 

NAME = pipex
SRC_DIR = .
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
HEADER_FILE = pipex.h
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF)/libmlx.a
FT_PRINTF_INC = -I$(FT_PRINTF_DIR)

all: $(NAME)

$(FT_PRINTF_LIB):
        $(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) | $(FT_PRINTF_LIB)
        $(CC) $(FLAGS) $(OBJS) -L$(FT_PRINTF_DIR) $(NAME)

%.o: %.c
        $(CC) $(FLAGS) -c $< -o $@

clean:
        rm -f $(OBJS)
        $(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
        rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re