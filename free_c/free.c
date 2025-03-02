/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:56:54 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 02:56:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void	free_map(t_data *data)
{
	int	i;

	if (!data || !data->map)
		return ;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

void	ft_destroy_images(t_data *data)
{
	if (data->img_collectable)
		mlx_destroy_image(data->mlx, data->img_collectable);
	if (data->img_door)
		mlx_destroy_image(data->mlx, data->img_door);
	if (data->img_ground)
		mlx_destroy_image(data->mlx, data->img_ground);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_collectable)
		mlx_destroy_image(data->mlx, data->img_wall);
}

void	free_arrays(t_data *data)
{
	free(data->collectable_arr);
	free(data->exit_arr);
	free(data->wall_arr);
	free(data->line_count);
}

void	ft_free_all_allocated_memory(t_data *data)
{
	ft_destroy_images(data);
	free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_arrays(data);
	free(data->filename);
	free(data->game_name);
	free(data->mlx);
	free(data);
}
