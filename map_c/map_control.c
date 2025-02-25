#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

char **load_map(char *filename, int *rows, t_data *data)
{
    int     fd;
    char    *line;

    line = NULL;
    fd = open(filename, O_RDONLY);
    *rows = load_map_1(fd, line);
    close(fd);
    fd = open(filename, O_RDONLY);
    load_map_2(data, line, fd, rows);
	close(fd);
    data->map = malloc(sizeof(char *) * ((*rows) + 1));
    if (data->map == NULL)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
	{
		free(data->map);
        return (NULL);
	}
    load_map_3(data, line, fd);
    close(fd);
    return (data->map);
}

void create_map_help_general(int x, int y, t_data *data, int *data_count, char param)
{
    if (data->map[y][x] == param)
		(*data_count)++;
}

void create_map_help(int x, int y, t_data *data)
{
    if (data->map[y][x] == '0')
        mlx_put_image_to_window(data->mlx, data->win, data->img_ground, x * data->pixel_size, y * data->pixel_size);
    else if (data->map[y][x] == '1' && data->wall_index + 1 < data->wall_count * 2)
    {
        just_one_line(data->wall_arr, &data->wall_index, &x, &y, data);
        mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x * data->pixel_size, y * data->pixel_size);
    }
    else if (data->map[y][x] == 'P')
    {
        data->player_x = x * data->pixel_size;
        data->player_y = y * data->pixel_size;
        mlx_put_image_to_window(data->mlx, data->win, data->img_player, data->player_x, data->player_y);
    }
    else if (data->map[y][x] == 'E')
	{
        data->exit_arr[0] = x * data->pixel_size;
		data->exit_arr[1] = y * data->pixel_size;
        mlx_put_image_to_window(data->mlx, data->win, data->img_door, x * data->pixel_size, y * data->pixel_size);
	}
    else if (data->map[y][x] == 'C' && data->collectable_index + 1 < data->collectable_count * 2)
	{
        just_one_line(data->collectable_arr, &data->collectable_index, &x, &y, data);
        mlx_put_image_to_window(data->mlx, data->win, data->img_collectable, x * data->pixel_size, y * data->pixel_size);
	}
}

void create_map(t_data *data)
{
    int     x;
    int     y;

    y = 0;
	if (!data->map)
    	return;
    while (data->map[y] != NULL)
    {
        x = 0;
        while (data->map[y][x])
        {
            create_map_help(x, y, data);
            x++;
        }
        y++;
    }
}
void update_map(t_data *data, int x, int y)
{
	int i1;

	i1 = 0;
	data->step_counter++;
	if (data->collected_count == data->collectable_count
            && (data->exit_arr[0] == (data->player_x + (data->pixel_size * x)) && data->exit_arr[1] == (data->player_y + (data->pixel_size * y))))
		ft_close_game(data);
	while (i1 + 1 < data->collectable_count * 2)
	{
		if (data->collectable_arr[i1] == (data->player_x + (data->pixel_size * x)) && data->collectable_arr[i1 + 1] == (data->player_y + (data->pixel_size * y)))
		{
			data->collectable_arr[i1] = 2348902;
			data->collectable_arr[i1 + 1] = 2348902;
			data->collected_count++;
		}
		i1+=2;
	}
	if (!(data->exit_arr[0] == (data->player_x + (data->pixel_size * x)) && data->exit_arr[1] == (data->player_y + (data->pixel_size * y))))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img_ground, data->player_x, data->player_y);
		data->player_x += data->pixel_size * x;
		data->player_y += data->pixel_size * y;
		mlx_put_image_to_window(data->mlx, data->win, data->img_player, data->player_x, data->player_y);
	}
	ft_printf("step counter: %d\n", data->step_counter);
}
