/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:15:58 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 03:15:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

void	cannot_start(t_data *data)
{
	if (data->flag == 1)
	{
		ft_printf("kral oyun başlayamadı üzgünüm\n");
		ft_close_game2(data);
	}
	if (data->screen_x < 0 || data->screen_y < 0
		|| !(data -> game_name) || !(data -> filename))
	{
		ft_printf("kral oyun başlayamadı üzgünüm\n");
		ft_close_game(data);
	}
}

void	cannot_ber(t_data *data, int len_filename)
{
	if (len_filename > 4)
	{
		if (ft_strncmp(data->filename + len_filename - 4, ".ber", 4) != 0)
		{
			ft_printf("kral oyun başlayamadı üzgünüm 4444\n");
			ft_close_game2(data);
		}
	}
	else
	{
		ft_printf("kral oyun başlayamadı üzgünüm len <= 4n");
		ft_close_game2(data);
	}
}
