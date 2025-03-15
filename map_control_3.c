/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:40:22 by marvin            #+#    #+#             */
/*   Updated: 2025/03/15 18:24:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void	check_exit_condition(t_data *data, int x, int y)
{
	if (data->collected_count == data->collectable_count
		&& data->exit_arr[0] == data->player_x + (data->pixel_size * x)
		&& data->exit_arr[1] == data->player_y + (data->pixel_size * y))
		ft_close_game(data);
}

void	update_collectable(t_data *data, int x, int y)
{
	int	i1;
	int	px;
	int	py;

	i1 = 0;
	px = data->pixel_size * x;
	py = data->pixel_size * y;
	while (i1 + 1 < data->collectable_count * 2)
	{
		if (data->collectable_arr[i1] == data->player_x + px
			&& data->collectable_arr[i1 + 1] == data->player_y + py)
		{
			data->collectable_arr[i1] = 2348902;
			data->collectable_arr[i1 + 1] = 2348902;
			data->collected_count++;
		}
		i1 += 2;
	}
}

void	move_player(t_data *data, int x, int y)
{
	if (!(data->exit_arr[0] == data->player_x + (data->pixel_size * x)
			&& data->exit_arr[1] == data->player_y + (data->pixel_size * y)))
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_ground, data->player_x, data->player_y);
		data->player_x += data->pixel_size * x;
		data->player_y += data->pixel_size * y;
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_player, data->player_x, data->player_y);
	}
}

void	update_map(t_data *data, int x, int y)
{
	data->step_counter++;
	check_exit_condition(data, x, y);
	update_collectable(data, x, y);
	move_player(data, x, y);
	ft_printf("Step counter: %d\n", data->step_counter);
}
