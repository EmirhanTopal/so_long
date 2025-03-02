/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:22:03 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 03:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void	create_map_help_general(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'C')
		data->collectable_count++;
	else if (data->map[y][x] == 'E')
		data->exit_count++;
	else if (data->map[y][x] == 'P')
		data->player_count++;
	else if (data->map[y][x] == '1')
		data->wall_count++;
}

void	put_image_to_window(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win,
		img, x * data->pixel_size, y * data->pixel_size);
}

void	create_map_help_only_c_for_line(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C'
		&& data->collectable_index + 1 < data->collectable_count * 2)
	{
		data->collectable_arr[data->collectable_index++] = data->pixel_size * x;
		data->collectable_arr[data->collectable_index++] = data->pixel_size * y;
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_collectable, x * data->pixel_size, y * data->pixel_size);
	}
}

void	create_map_help(int x, int y, t_data *data)
{
	if (data->map[y][x] == '0')
		put_image_to_window(data, data->img_ground, x, y);
	else if (data->map[y][x] == '1'
		&& data->wall_index + 1 < data->wall_count * 2)
	{
		data->wall_arr[data->wall_index++] = data->pixel_size * x;
		data->wall_arr[data->wall_index++] = data->pixel_size * y;
		put_image_to_window(data, data->img_wall, x, y);
	}
	else if (data->map[y][x] == 'P')
	{
		data->player_x = x * data->pixel_size;
		data->player_y = y * data->pixel_size;
		put_image_to_window(data, data->img_player, x, y);
	}
	else if (data->map[y][x] == 'E')
	{
		data->exit_arr[0] = x * data->pixel_size;
		data->exit_arr[1] = y * data->pixel_size;
		put_image_to_window(data, data->img_door, x, y);
	}
	create_map_help_only_c_for_line(data, x, y);
}

void	create_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->map)
		return ;
	while (data->map[y])
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
