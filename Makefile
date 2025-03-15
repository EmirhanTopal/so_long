NAME = so_long
CC = cc
RM = rm -rf
MLX_DIR = ./mlx
GETNEXT_DIR = ./get_next_line
PRINTF_DIR = ./printf

CFLAGS = -Wall -Wextra -Werror -g -I$(MLX_DIR) -I$(GETNEXT_DIR) -I$(PRINTF_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
FILES = main.c \
	ft_utils.c \
	$(GETNEXT_DIR)/get_next_line.c \
	$(GETNEXT_DIR)/get_next_line_utils.c \
	check.c \
	check_2.c \
	dfs_control.c \
	dfs_control_2.c \
	free.c \
	free_2.c \
	init_game.c \
	init_game_2.c \
	key_handle.c \
	map_control.c \
	map_control_2.c \
	map_control_3.c 


OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_DIR)/libftprintf.a	$(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
