/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtopal <emtopal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:39:41 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 13:14:17 by emtopal          ###   ########.fr       */
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
	void	*img_ground;
	void	*img_wall;
	void	*img_collectable;
	void	*img_door;
	int		player_x;
	int		player_y;
	int		screen_x;
	int		screen_y;
	int		pixel_size;
	int		step_counter;
	int		rows;
	int		*visited_arr;
	int		visited_index;
	int		visited_count;
	int		*collectable_arr;
	int		collectable_count;
	int		collectable_index;
	int		collected_count;
	int		collected_control_count;
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
	char	*filename;
	char	*game_name;
	int		u_x;
	int		l_y;
	int		lw_x;
	int		r_y;
	int		len;
}	t_data;

void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif