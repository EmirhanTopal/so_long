#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	i = 0;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

void just_one_line(int *arr, int *index, int *x, int *y, t_data *data)
{   
    arr[(*index)++] = *x * data->pixel_size;
    arr[(*index)++] = *y * data->pixel_size;
}
