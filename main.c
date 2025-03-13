/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:38:27 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 22:39:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"
#include "dfs_control.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("kral argc yanlış 2 yap 2");
		return (-1);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (0);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_close_game(data);
	init_game(data, argv);
	data->win = mlx_new_window(data->mlx, data->screen_x,
			data->screen_y, data->game_name);
	ft_xpm_to_image(data);
	create_map(data);
	is_rectangular(data);
	dfs_control(data);
	mlx_key_hook(data->win, handle_key_input, data);
	mlx_loop(data->mlx);
	ft_close_game(data);
	return (0);
}
