/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:34:18 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 00:08:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dfs_control.h"
#include "free.h"

void	dfs_add_to_visited(t_data *data, int x, int y)
{
	data->visited_arr[data->visited_index++] = x;
	data->visited_arr[data->visited_index++] = y;
}

int	is_visited(t_data *data, int x, int y, int index)
{
	if (index >= data->visited_index)
		return (0);
	if (data->visited_arr[index] == x && data->visited_arr[index + 1] == y)
		return (1);
	return (is_visited(data, x, y, index + 2));
}

int	is_wall(t_data *data, int x, int y, int index)
{
	if (index >= data->wall_count * 2)
		return (0);
	if (data->wall_arr[index] == x && data->wall_arr[index + 1] == y)
		return (1);
	return (is_wall(data, x, y, index + 2));
}

int	is_collectable(t_data *data, int x, int y, int index)
{
	if (index >= data->collectable_count * 2)
		return (0);
	if (data->collectable_arr[index] == x
		&& data->collectable_arr[index + 1] == y)
		return (1);
	return (is_collectable(data, x, y, index + 2));
}
