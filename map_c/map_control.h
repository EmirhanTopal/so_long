#ifndef MAP_CONTROL_H
#define MAP_CONTROL_H

#include "so_long.h"

char 	**load_map(char *filename, int *rows, t_data *data);
void 	create_map_help_general(int x, int y, t_data *data, int *data_count, char param);
void 	create_map_help(int x, int y, t_data *data);
void 	create_map(t_data *data);
void 	update_map(t_data *data, int x, int y);

#endif