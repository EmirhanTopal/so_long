#include "dfs_control.h"
#include "free.h"

// void	dfs_control_help_visited(t_data *data, int x, int y)
// {
// 	while (data->visited_count + 1 < data->visited_index)
//     {
//         if (data->visited_arr[data->visited_count] == x && data->visited_arr[data->visited_count + 1] == y)
//             return ;
//         data->visited_count++;
//     }
// }

// void	dfs_control_help_wall(t_data *data, int x, int y)
// {
// 	int w_index;

// 	w_index = 0;
//     while (w_index + 1 < data->wall_count * 2)
//     {
//         if (data->wall_arr[w_index] == x && data->wall_arr[w_index + 1] == y)
//             return ;
//         w_index += 2;  // İşaretçi doğru şekilde güncelleniyor
//     }
// }

// void	dfs_control_help_collectable(t_data *data, int x, int y)
// {
// 	int c_index;

// 	c_index = 0;
//     while (c_index + 1 < data->collectable_count * 2)
//     {
//         if (data->collectable_arr[c_index] == x && data->collectable_arr[c_index + 1] == y)
//             data->collected_control_count++;
//         c_index += 2;  // İşaretçi doğru şekilde güncelleniyor
//     }
// }

void dfs_main_control(t_data *data, int x, int y)
{
    int wall_index;
    int collectable_index;

    wall_index = 0;
    collectable_index = 0;
    data->visited_count = 0;
    if (data->visited_index >= data->screen_x * data->screen_y * 2)
	{
        return ;
	}
    //dfs_control_help_visited(data, x, y);
	while (data->visited_count + 1 < data->visited_index)
    {
        if (data->visited_arr[data->visited_count] == x && data->visited_arr[data->visited_count + 1] == y)
            return ;
        data->visited_count++;
    }
	data->visited_arr[data->visited_index++] = x;
    data->visited_arr[data->visited_index++] = y;
    if (wall_index >= data->wall_count * 2) 
	{
        return ;
	}
    //dfs_control_help_wall(data, x, y, wall_index);
	while (wall_index + 1 < data->wall_count * 2)
    {
        if (data->wall_arr[wall_index] == x && data->wall_arr[wall_index + 1] == y)
            return ;
        wall_index += 2;  // İşaretçi doğru şekilde güncelleniyor
    }
    if (data->exit_arr[0] == x && data->exit_arr[1] == y)
            return ;
    if (collectable_index >= data->collectable_count * 2) 
    {
        return ;
	}
    //dfs_control_help_collectable(data, x, y, collectable_index);
	while (collectable_index + 1 < data->collectable_count * 2)
    {
        if (data->collectable_arr[collectable_index] == x && data->collectable_arr[collectable_index + 1] == y)
            data->collected_control_count++;
        collectable_index += 2;  // İşaretçi doğru şekilde güncelleniyor
    }
    dfs_main_control(data, x + data->pixel_size, y);
    dfs_main_control(data, x - data->pixel_size, y);
    dfs_main_control(data, x, y + data->pixel_size);
    dfs_main_control(data, x, y - data->pixel_size);
}

void    dfs_control(t_data *data)
{
    dfs_main_control(data, data->player_x, data->player_y);
    if (data->collected_control_count != data->collectable_count)
    {
        ft_printf("kral bu çalışmaz başka map dene");
        ft_close_game(data);
    }
}
