/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:39:41 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 17:40:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	g_ground;
	void	g_wall;
	void	g_collectable;
	void	g_door;
	int		player_x;
	int		player_y;
	int		screen_x;
	int		screen_y;
	int		pixel_size;
	int		step_counter;
	int		rows;
	int		*collectable_arr;
	int		collectable_count;
	int		collectable_index;
	int		collected_count;
	int		*wall_arr;
	int		wall_count;
	int		wall_index;
	int		*exit_arr;
	int		exit_count;
	int		player_count;
	int		*line_count;
	int		line_count_index;
	char	**map;
	int		flag;
	char	filename;
	char	game_name;
	int		u_x;
	int		l_y;
	int		lw_x;
	int		r_y;
	int		len;
}	t_data;

void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif