/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:18:25 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 03:18:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void	handle_key_help(int keycode_help, t_data *data)
{
	int	p_size;

	p_size = data->pixel_size;
	if (keycode_help == 119
		&& !wall_check(data, data->player_x, data->player_y - p_size))
		update_map(data, 0, -1);
	else if (keycode_help == 115
		&& !wall_check(data, data->player_x, data->player_y + p_size))
		update_map(data, 0, 1);
	else if (keycode_help == 97
		&& !wall_check(data, data->player_x - p_size, data->player_y))
		update_map(data, -1, 0);
	else if (keycode_help == 100
		&& !wall_check(data, data->player_x + p_size, data->player_y))
		update_map(data, 1, 0);
}

int	handle_key_input(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_close_game(data);
	handle_key_help(keycode, data);
	return (0);
}
