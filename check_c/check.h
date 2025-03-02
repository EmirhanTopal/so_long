/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:50:51 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 02:50:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "so_long.h"

int		wall_check(t_data *data, int p_x, int p_y);
void	is_rectangular_help(int *edge_value, int *flag);
int		is_rectangular(t_data *data);
void	check_wall_conditions(t_data *data, int *flag, int x_y2);

#endif
