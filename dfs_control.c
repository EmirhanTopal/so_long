/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:15:01 by marvin            #+#    #+#             */
/*   Updated: 2025/03/15 18:20:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "dfs_control.h"
#include "free.h"

void	dfs_main_control(t_data *data, int x, int y)
{
	if (data->visited_index >= data->screen_x * data->screen_y * 2
		|| is_visited(data, x, y, 0))
		return ;
	dfs_add_to_visited(data, x, y);
	if (is_wall(data, x, y, 0) || (data->exit_arr[0] == x
			&& data->exit_arr[1] == y))
		return ;
	if (is_collectable(data, x, y, 0))
		data->collected_control_count++;
	dfs_main_control(data, x + data->pixel_size, y);
	dfs_main_control(data, x - data->pixel_size, y);
	dfs_main_control(data, x, y + data->pixel_size);
	dfs_main_control(data, x, y - data->pixel_size);
}

void	dfs_control(t_data *data)
{
	dfs_main_control(data, data->player_x, data->player_y);
	if (data->collected_control_count != data->collectable_count)
	{
		ft_printf("inaccessable coin finded");
		ft_close_game(data);
	}
}
