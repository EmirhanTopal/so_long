/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtopal <emtopal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:18:04 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 13:23:27 by emtopal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H

# include "so_long.h"

void	ft_xpm_to_image(t_data *data);
void	ft_open_malloc(t_data *data);
void	init_game(t_data *data, char **argv);
void	cannot_start(t_data *data);
void	cannot_ber(t_data *data, int len_filename);
int		has_trailing_newline(char *line);
#endif