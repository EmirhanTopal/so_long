#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "mlx/mlx_int.h"
#include "get_next_line/get_next_line.h"
#include "printf/ft_printf.h"

typedef struct s_data
{
    void	*mlx;
    void	*win;
    void	*img_player;
    void	*img_ground;
    void	*img_wall;
    void	*img_collectable;
    void	*img_door;
    int     player_x;
    int     player_y;
    int     screen_x;
    int     screen_y;
    int     pixel_size;
    int     step_counter;
    int     rows;
    int     *collectable_arr;
    int     collectable_count;
    int     collectable_index;
    int     collected_count;
    int     *wall_arr;
    int     wall_count;
    int     wall_index;
    int     *exit_arr;
    int     exit_count;
    int     player_count;
    int     *line_count;
    int     line_count_index;
    char    **map;
    int     flag;
	char	*filename;
	char	*game_name;
} t_data;

void	*ft_calloc(size_t count, size_t size);
void    just_one_line(int *arr, int *index, int *x, int *y, t_data *data);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);

#endif