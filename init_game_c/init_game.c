/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:05:40 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 03:05:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void	ft_xpm_to_image(t_data *data)
{
	data->img_ground = mlx_xpm_file_to_image(data->mlx, "xpm_images/ground.xpm",
			&data->pixel_size, &data->pixel_size);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "xpm_images/wall.xpm",
			&data->pixel_size, &data->pixel_size);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "xpm_images/player.xpm",
			&data->pixel_size, &data->pixel_size);
	data->img_collectable = mlx_xpm_file_to_image(data->mlx,
			"xpm_images/collectable.xpm",
			&data->pixel_size, &data->pixel_size);
	data->img_door = mlx_xpm_file_to_image(data->mlx, "xpm_images/door.xpm",
			&data->pixel_size, &data->pixel_size);
}

void	ft_open_malloc(t_data *data)
{
	if (data->player_count > 1 || data->exit_count > 1
		|| data->collectable_count < 1)
	{
		ft_printf("dostum player c: %d, exit c: %d, collectable c: %d",
			data->player_count, data->exit_count, data->collectable_count);
		ft_close_game(data);
	}
	data->collectable_arr = malloc(sizeof(int) * (data->collectable_count * 2));
	data->wall_arr = malloc(sizeof(int) * (data->wall_count * 2));
	data->exit_arr = malloc(sizeof(int) * 2);
}

void	data_init(t_data *data, char **argv)
{
	int	len_filename;

	data->pixel_size = 64;
	data->game_name = ft_strdup("so_long");
	data->filename = ft_strdup(argv[1]);
	len_filename = ft_strlen(data->filename);
	cannot_ber(data, len_filename);
	data->map = load_map(argv[1], &data->rows, data);
	data->screen_x = (ft_strlen(data->map[0]) - 2) * data->pixel_size;
	data->screen_y = data->rows * data->pixel_size;
}

void	cannot_init(t_data *data)
{
	int	a;
	int	i;

	if (data->line_count == NULL || data->line_count_index <= 0)
		return ;
	a = data->line_count[0];
	i = 0;
	while (i < data->line_count_index)
	{
		if (data->line_count[i] != a)
			data->flag = 1;
		i++;
	}
	cannot_start(data);
}

void	init_game(t_data *data, char **argv)
{
	int	x;
	int	y;

	data_init(data, argv);
	cannot_init(data);
	if (!data->map)
		return ;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x])
		{
			create_map_help_general(x, y, data);
			x++;
		}
		y++;
	}
	ft_open_malloc(data);
}
