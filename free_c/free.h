#ifndef FREE_H
#define FREE_H

#include "so_long.h"

void    free_map(t_data *data);
void	ft_destroy_images(t_data *data);
void    free_arrays(t_data *data);
void	ft_free_all_allocated_memory(t_data *data);
int		ft_close_game(void *data);

#endif