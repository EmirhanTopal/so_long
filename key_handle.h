/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:21:32 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 03:21:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLE_H
# define KEY_HANDLE_H

# include "so_long.h"

void	handle_key_help(int keycode_help, t_data *data);
int		handle_key_input(int keycode, t_data *data);

#endif