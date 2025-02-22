#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void ft_xpm_to_image(t_data *data)
{
    data->img_ground = mlx_xpm_file_to_image(data->mlx, "xpm_images/ground.xpm", &data->pixel_size, &data->pixel_size);
    data->img_wall = mlx_xpm_file_to_image(data->mlx, "xpm_images/wall.xpm", &data->pixel_size, &data->pixel_size);
    data->img_player = mlx_xpm_file_to_image(data->mlx, "xpm_images/player.xpm", &data->pixel_size, &data->pixel_size);
    data->img_collectable = mlx_xpm_file_to_image(data->mlx, "xpm_images/collectable.xpm", &data->pixel_size, &data->pixel_size);
    data->img_door = mlx_xpm_file_to_image(data->mlx, "xpm_images/door.xpm", &data->pixel_size, &data->pixel_size);
}

void ft_open_malloc(t_data *data)
{
    if (data->player_count > 1 || data->exit_count > 1 || data->collectable_count < 1)
    {
        ft_printf("dostum player count: %d, exit count: %d, collectable count: %d - bunları bir kontrol et sana zahmet", data->player_count, data->exit_count, data->collectable_count);
        ft_close_game(data);
    }
    else if (data->screen_x == 5 && data->screen_y == 3)
    data->collectable_arr = malloc(sizeof(int) * (data->collectable_count * 2));
    data->wall_arr = malloc(sizeof(int) * (data->wall_count * 2));
	data->exit_arr = malloc(sizeof(int) * 2);
}

void data_init(t_data *data, char **argv)
{
    data->pixel_size = 64;
    data->game_name = ft_strdup("so_long");
    data->filename = ft_strdup(argv[1]);
    data->map = load_map(argv[1], &data->rows, data);
    data->screen_x = (ft_strlen(data->map[0]) - 2) * data->pixel_size;
	data->screen_y = data->rows * data->pixel_size;
}

void cannot_init(t_data *data)
{
    if (data->screen_x < 0 || data->screen_y < 0
		|| !(data -> game_name) || !(data -> filename))
	{
		ft_printf("kral oyun başlayamadı üzgünüm\n");
		ft_close_game(data);
	}
}

void init_game(t_data *data, char **argv)
{
	int     x;
    int     y;

	data_init(data, argv);
    cannot_init(data);
	if (!data->map)
    	return;
    y = 0;
    while (data->map[y] != NULL)
    {
        x = 0;
        while (data->map[y][x])
        {
            create_map_help_general(x, y, data, &data->collectable_count, 'C');
            create_map_help_general(x, y, data, &data->wall_count, '1');
            create_map_help_general(x, y, data, &data->player_count, 'P');
            create_map_help_general(x, y, data, &data->exit_count, 'E');
            x++;
        }
        y++;
    }
	ft_open_malloc(data);
}
