#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void handle_key_help(int keycode_help, t_data *data)
{
	int p_size;

	p_size = data->pixel_size;
    if (keycode_help == 119 && !wall_check(data, data->player_x, data->player_y - p_size))
        update_map(data, 0, -1); // W
    else if (keycode_help == 115 && !wall_check(data, data->player_x, data->player_y + p_size))
        update_map(data, 0, 1); // S
    else if (keycode_help == 97 && !wall_check(data, data->player_x - p_size, data->player_y))
        update_map(data, -1, 0); // A
    else if (keycode_help == 100 && !wall_check(data, data->player_x + p_size, data->player_y)) 
        update_map(data, 1, 0); // D
}

int handle_key_input(int keycode, t_data *data)
{
    if (keycode == 65307)
        ft_close_game(data);
    handle_key_help(keycode, data);
    return (0);
}