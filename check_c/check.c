/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:24:04 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 02:24:04 by marvin           ###   ########.fr       */
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

void	is_rectangular_help(int *edge_value, int *flag)
{
	(*edge_value) += 64;
	(*flag) = 1;
}

void	check_wall_conditions(t_data *data, int *flag, int x_y2)
{
	if (data->u_x == data->wall_arr[x_y2] && data->wall_arr[x_y2 + 1] == 0
		&& data->u_x <= data->screen_x - data->pixel_size)
		is_rectangular_help(&data->u_x, flag);
	else if (data->lw_x == data->wall_arr[x_y2]
		&& data->wall_arr[x_y2 + 1] == data->screen_y - data->pixel_size
		&& data->lw_x <= data->screen_x - data->pixel_size)
		is_rectangular_help(&data->lw_x, flag);
	else if (data->wall_arr[x_y2] == 0
		&& data->wall_arr[x_y2 + 1] == data->l_y
		&& data->l_y <= data->screen_y - data->pixel_size)
		is_rectangular_help(&data->l_y, flag);
	else if (data->wall_arr[x_y2] == data->screen_x - data->pixel_size
		&& data->wall_arr[x_y2 + 1] == data->r_y
		&& data->r_y <= data->screen_y - data->pixel_size)
		is_rectangular_help(&data->r_y, flag);
	if ((data->wall_arr[x_y2] != data->screen_x - data->pixel_size
			&& data->wall_arr[x_y2] != 0)
		&& (data->wall_arr[x_y2 + 1] != data->screen_y - data->pixel_size
			&& data->wall_arr[x_y2 + 1] != 0))
		*flag = 1;
	else
		*flag = 0;
}

int	is_rectangular(t_data *data)
{
	int	x_y2;
	int	flag;

	flag = 1;
	x_y2 = 0;
	while (x_y2 + 2 < data->wall_count * 2)
	{
		check_wall_conditions(data, &flag, x_y2);
		x_y2++;
	}
	if (flag == 0)
	{
		ft_printf("kral bu iş olmadı");
		ft_close_game(data);
	}
	return (EXIT_SUCCESS);
}
