/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:22:21 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 16:22:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DFS_CONTROL_H
# define DFS_CONTROL_H

# include "so_long.h"

void	dfs_main_control(t_data *data, int x, int y);
void	dfs_control(t_data *data);
void	dfs_add_to_visited(t_data *data, int x, int y);
int		is_visited(t_data *data, int x, int y, int index);
int		is_wall(t_data *data, int x, int y, int index);
int		is_collectable(t_data *data, int x, int y, int index);

#endif