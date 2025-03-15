/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:20:43 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 22:20:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void	top_control(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->wall_count * 2)
	{
		if (data->wall_arr[i + 1] == 0 && data->wall_arr[i] == data->u_x)
			is_rectangular_help(&data->u_x);
		i += 2;
	}
	if (data->u_x != data->screen_x)
		ft_close_game(data);
}

void	left_control(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->wall_count * 2)
	{
		if (data->wall_arr[i] == 0 && data->wall_arr[i + 1] == data->l_y)
			is_rectangular_help(&data->l_y);
		i += 2;
	}
	if (data->l_y != data->screen_y)
		ft_close_game(data);
}

void	right_control(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->wall_count * 2)
	{
		if (data->wall_arr[i] == data->screen_x - data->pixel_size
			&& data->wall_arr[i + 1] == data->r_y)
			is_rectangular_help(&data->r_y);
		i += 2;
	}
	if (data->r_y != data->screen_y)
		ft_close_game(data);
}

void	bottom_control(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->wall_count * 2)
	{
		if (data->wall_arr[i + 1] == data->screen_y - data->pixel_size
			&& data->wall_arr[i] == data->lw_x)
			is_rectangular_help(&data->lw_x);
		i += 2;
	}
	if (data->lw_x != data->screen_x)
		ft_close_game(data);
}
