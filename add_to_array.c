#include <fdf.h>

void	realloc_array(map_t *map)
{
	int		**new;
	int		y;

	if (!(new = (int **)malloc(sizeof(int *) * (map->column + 2))))
		exit(0);
	y = -1;
	while (++y < map->column)
		new[y] = map->iarray[y];
	if (map->column != 0)
	{
		free(map->iarray[y]);
		free(map->iarray);
	}
	if (!(new[y + 1] = (int *)malloc(sizeof(int))))
		exit(0);
	new[y + 1][0] = -1;
	map->iarray = new;
}

int		array_size(char **array)
{
	int		count;

	count = 0;
	while (*array++)
		count++;
	return (count);
}

void	add_row(char **array, map_t *map)
{
	int		x;
	int		size;

	size = array_size(array);
	if (map->column == 0)
		map->row = size;
	else if (size != map->row)
		exit(0); //The row sizes do not match
	if (!(map->iarray = (int *)malloc(sizeof(int) * (size + 1))))
		exit(0);
	x = -1; 
	while (array[++x])
		map->iarray[x] = ft_atoi(array[x]);
	map->iarray[x] = -1;
}

void	add_to_array(char **array, map_t *map)
{
	realloc_array(map);
	map->iarray[map->column] = add_row(array);
}