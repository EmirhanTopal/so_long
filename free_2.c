/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:52:59 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 00:00:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

int	ft_close_game(void *data)
{
	t_data	*data2;

	if (data == NULL)
	{
		ft_free_all_allocated_memory(data);
		ft_printf("data is null \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		(void)data;
		data2 = (t_data *)data;
		ft_printf("Exit Failure \n");
		ft_free_all_allocated_memory(data2);
	}
	exit(EXIT_FAILURE);
}

int	ft_close_game2(t_data *data)
{
	ft_printf("Game cannot started \n");
	free_map(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_arrays(data);
	free(data->filename);
	free(data->game_name);
	free(data);
	exit(EXIT_FAILURE);
}

int	ft_close_game_success(void *data)
{
	t_data	*data2;

	if (data == NULL)
	{
		ft_free_all_allocated_memory(data);
		ft_printf("data is null \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		(void)data;
		data2 = (t_data *)data;
		ft_printf("Exit Success \n");
		ft_free_all_allocated_memory(data2);
	}
	exit(EXIT_SUCCESS);
}
