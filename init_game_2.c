/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:15:58 by marvin            #+#    #+#             */
/*   Updated: 2025/03/19 14:33:05 by marvin           ###   ########.fr       */
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
		ft_printf("Game cannot started \n");
		ft_close_game2(data);
	}
	if (data->screen_x < 0 || data->screen_y < 0
		|| !(data -> game_name) || !(data -> filename))
	{
		ft_printf("Game cannot started\n");
		ft_close_game(data);
	}
}

void	cannot_ber(t_data *data, int len_filename)
{
	char	*temp_filename;
	
	temp_filename = ft_strchr(data->filename, '/');
	temp_filename++;
	if (len_filename > 5)
	{
		if (ft_strlen(temp_filename) < 5)
		{
			ft_printf("File type is wrong\n");
			ft_close_game2(data);
		}
		if (ft_strncmp(data->filename + len_filename - 4, ".ber", 5) != 0)
		{
			ft_printf("File type is wrong\n");
			ft_close_game2(data);
		}
	}
	else
	{
		ft_printf("File type and lenght is wrong\n");
		ft_close_game2(data);
	}
}

int	has_trailing_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		return (1);
	return (0);
}
