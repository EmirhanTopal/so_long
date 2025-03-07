#include "dfs_control.h"
#include "free.h"


void dfs_control(t_data *data, int x, int y)
{
    int wall_index;
    int collectable_index;

    wall_index = 0;
    collectable_index = 0;
    data->visited_count = 0;
    if (data->visited_index >= data->screen_x * data->screen_y * 2) {
        ft_printf("array dışına çıktın yavaş - visited\n");
        return;
    }
    while (data->visited_count + 1 < data->visited_index)
    {
        if (data->visited_arr[data->visited_count] == x && data->visited_arr[data->visited_count + 1] == y)
            return ;
        data->visited_count++;
    }
    data->visited_arr[data->visited_index++] = x;
    data->visited_arr[data->visited_index++] = y;
    if (wall_index >= data->wall_count * 2) {
        ft_printf("array dışına çıktın yavaş - wall\n");
        return;
    }
    while (wall_index + 1 < data->wall_count * 2)
    {
        if (data->wall_arr[wall_index] == x && data->wall_arr[wall_index + 1] == y)
            return ;
        wall_index += 2;
    }
    if (data->exit_arr[0] == x && data->exit_arr[1] == y)
            return ;
    if (collectable_index >= data->collectable_count * 2) {
        ft_printf("array dışına çıktın yavaş - collectable\n");
        return;
    }
    while (collectable_index + 1 < data->collectable_count * 2)
	{
		if (data->collectable_arr[collectable_index] == x && data->collectable_arr[collectable_index + 1] == y)
            data->collected_control_count++;
		collectable_index+=2;
	}
    dfs_control(data, x + data->pixel_size, y);
    dfs_control(data, x - data->pixel_size, y);
    dfs_control(data, x, y + data->pixel_size);
    dfs_control(data, x, y - data->pixel_size);
}

void    dfs_main_control(t_data *data)
{
    dfs_control(data, data->player_x, data->player_y);
    if (data->collected_control_count != data->collectable_count)
    {
        ft_printf("kral bu çalışmaz başka map dene");
        ft_close_game(data);
    }
}