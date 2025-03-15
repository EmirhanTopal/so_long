/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:24:04 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 22:49:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

int	wall_check(t_data *data, int p_x, int p_y)
{
	int	x_y;

	x_y = 0;
	while (x_y < data->wall_count * 2)
	{
		if (data->wall_arr[x_y] == p_x && data->wall_arr[x_y + 1] == p_y)
			return (1);
		x_y += 2;
	}
	return (0);
}

void	is_rectangular_help(int *edge_value)
{
	(*edge_value) += 64;
}

void	is_rectangular(t_data *data)
{
	data->u_x = 0;
	data->lw_x = 0;
	data->l_y = 64;
	data->r_y = 64;
	top_control(data);
	left_control(data);
	right_control(data);
	bottom_control(data);
}
