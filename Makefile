NAME = so_long
CC = cc
RM = rm -rf
MLX_DIR = ./mlx
GETNEXT_DIR = ./get_next_line
PRINTF_DIR = ./printf
CHECK_DIR = ./check_c
KEY_DIR = ./key_c
MAP_DIR = ./map_c
FREE_DIR = ./free_c
INIT_DIR = ./init_game_c
DFS_DIR = ./dfs_c

CFLAGS = -Wall -Wextra -Werror -g -I. -Idfs_c -Iinit_game_c -Ifree_c -Icheck_c -Ikey_c -Imap_c -I$(MLX_DIR) -I$(GETNEXT_DIR) -I$(PRINTF_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
FILES = main.c \
	ft_utils.c \
	$(GETNEXT_DIR)/get_next_line.c \
	$(GETNEXT_DIR)/get_next_line_utils.c \
	$(CHECK_DIR)/check.c \
	$(DFS_DIR)/dfs_control.c \
	$(DFS_DIR)/dfs_control_2.c \
	$(FREE_DIR)/free.c \
	$(FREE_DIR)/free_2.c \
	$(INIT_DIR)/init_game.c \
	$(INIT_DIR)/init_game_2.c \
	$(KEY_DIR)/key_handle.c \
	$(MAP_DIR)/map_control.c \
	$(MAP_DIR)/map_control_2.c \
	$(MAP_DIR)/map_control_3.c 


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
