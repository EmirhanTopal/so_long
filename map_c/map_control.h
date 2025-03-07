/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:30:35 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 17:30:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CONTROL_H
# define MAP_CONTROL_H

# include "so_long.h"

char	**load_map(char *filename, int *rows, t_data *data);
void	create_map_help_only_c_for_line(t_data *data, int x, int y);
void	create_map_help_general(int x, int y, t_data *data);
void	create_map_help(int x, int y, t_data *data);
void	create_map(t_data *data);
void	check_exit_condition(t_data *data, int x, int y);
void	update_collectable(t_data *data, int x, int y);
void	move_player(t_data *data, int x, int y);
void	update_map(t_data *data, int x, int y);
int		load_map_1(int fd, char *line);
void	load_map_2(t_data *data, char *line, int fd, int *rows);
void	load_map_3(t_data *data, char *line, int fd);
void	put_image_to_window(t_data *data, void *img, int x, int y);

#endif