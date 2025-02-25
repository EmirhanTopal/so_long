#include "init_game.h"
#include "check.h"
#include "free.h"
#include "key_handle.h"
#include "map_control.h"

int load_map_1(int fd, char *line)
{
    int rows;

    rows = 0;
    if (fd < 0)
        return (-1);
    rows = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        rows++;
        free(line);
    }
    return (rows);
}

void load_map_2(t_data *data, char *line, int fd, int *rows)
{
    int i;
    int len;

    len = 0;
    i = 0;
    data->line_count = malloc(sizeof(int) * data->rows);
    while ((line = get_next_line(fd)) != NULL)
    {
        if(i < *rows)
        {
            len = ft_strlen(line);
            if (len > 0 && line[len - 1] == '\n')
                len -= 2;
            data->line_count[i] = len;
        }
        i++;
        free(line);
    }
    data->line_count_index = i;
}

void load_map_3(t_data *data, char *line, int fd)
{
    int i;

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
        data->map[i++] = line;
    data->map[i] = NULL;
}
