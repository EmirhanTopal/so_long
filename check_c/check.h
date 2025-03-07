#ifndef CHECK_H
#define CHECK_H

#include "so_long.h"

int wall_check(t_data *data, int p_x, int p_y);
void is_rectangular_help(int *edge_value, int *flag);
int is_rectangular(t_data *data);

#endif