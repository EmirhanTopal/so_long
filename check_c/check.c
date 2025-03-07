#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

int wall_check(t_data *data, int p_x, int p_y)
{
    int x_y;

    x_y = 0;
    while (x_y < data->wall_count * 2)
    {
        if (data->wall_arr[x_y] == p_x && data->wall_arr[x_y + 1] == p_y)
            return (1);
        x_y += 2;
    }
    return (0);
}

void is_rectangular_help(int *edge_value, int *flag)
{
    (*edge_value) += 64;
    (*flag) = 1;
}

int is_rectangular(t_data *data)
{
    int x_y2;
    int upper_x;
    int left_y;
    int lower_x;
    int right_y;
    int flag;

    flag = 1;
    upper_x = 0;
    left_y = 0;
    lower_x = 0;
    right_y = 0;
	x_y2 = 0;
	while (x_y2 + 2 < data->wall_count * 2)
	{
		if (upper_x == data->wall_arr[x_y2] && data->wall_arr[x_y2 + 1] == 0 && upper_x <= data->screen_x - data->pixel_size)
			is_rectangular_help(&upper_x, &flag);          
		else if(lower_x == data->wall_arr[x_y2] && data->wall_arr[x_y2 + 1] == data->screen_y - data->pixel_size && lower_x <= data->screen_x - data->pixel_size)
			is_rectangular_help(&lower_x, &flag);    
		else if(data->wall_arr[x_y2] == 0 && data->wall_arr[x_y2 + 1] == left_y && left_y <= data->screen_y - data->pixel_size)
			is_rectangular_help(&left_y, &flag);
		else if(data->wall_arr[x_y2] == data->screen_x - data->pixel_size && data->wall_arr[x_y2 + 1] == right_y && right_y <= data->screen_y - data->pixel_size)
			is_rectangular_help(&right_y, &flag);
		if((data->wall_arr[x_y2] != data->screen_x - data->pixel_size && data->wall_arr[x_y2] != 0) && 
			(data->wall_arr[x_y2 + 1] != data->screen_y - data->pixel_size && data->wall_arr[x_y2 + 1] != 0))
			flag = 1;
		else
			flag = 0;
		x_y2++;
    }
    if (flag == 0) 
    {
        ft_printf("kral bu iş olmadı");
        ft_close_game(data);
    }
    return (EXIT_SUCCESS);
}
