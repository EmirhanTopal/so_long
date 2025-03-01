#ifndef INIT_GAME_H
#define INIT_GAME_H

#include "so_long.h"

void    ft_xpm_to_image(t_data *data);
void    ft_open_malloc(t_data *data);
void    init_game(t_data *data, char **argv);
void    cannot_start(t_data *data);
void    cannot_ber(t_data *data, int len_filename);
#endif