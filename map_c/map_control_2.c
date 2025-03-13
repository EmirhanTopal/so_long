/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:45:05 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 22:45:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

char	**load_map(char *filename, int *rows, t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	*rows = load_map_1(fd, line);
	if (*rows <= 0)
		exit(1);
	fd = open(filename, O_RDONLY);
	data->line_count = malloc(sizeof(int) * data->rows);
	load_map_2(data, line, fd, rows);
	data->map = malloc(sizeof(char *) * ((*rows) + 1));
	if (data->map == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(data->map);
		return (NULL);
	}
	load_map_3(data, line, fd);
	return (data->map);
}

int	load_map_1(int fd, char *line)
{
	int	rows;
	int	control;

	rows = 0;
	control = 1;
	if (fd < 0)
		return (-1);
	rows = 0;
	while (control)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			control = 0;
		}
		else
			rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

void	load_map_2(t_data *data, char *line, int fd, int *rows)
{
	int	i;
	int	control;

	i = 0;
	control = 1;
	while (control)
	{
		line = get_next_line(fd);
		if (line == NULL)
			control = 0;
		if (control == 1)
		{
			if (i < *rows)
			{
				data->len = ft_strlen(line);
				if (data->len > 0 && line[data->len - 1] == '\n')
					data->len -= 2;
				data->line_count[i] = data->len;
			}
			i++;
		}
		free(line);
	}
	data->line_count_index = i;
	close(fd);
}

void	load_map_3(t_data *data, char *line, int fd)
{
	int	i;
	int	control;

	i = 0;
	control = 1;
	while (control)
	{
		line = get_next_line(fd);
		if (line == NULL)
			control = 0;
		else
			data->map[i++] = line;
	}
	data->map[i] = NULL;
	close(fd);
}
