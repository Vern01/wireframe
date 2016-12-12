#include "fdf.h"

void	realloc_array(map_t *map, int add_size)
{
	double	**new;
	int		y;

	if (!(new = (double **)malloc(sizeof(double *) * (map->node_size + add_size))))
		exit(0);
	y = -1;
	while (++y < map->node_size)
		new[y] = map->nodes[y];
	if (map->node_size != 0)
		free(map->nodes);
	map->nodes = new;
}

int		array_size(char **array)
{
	int		count;

	count = 0;
	while (*array++)
		count++;
	return (count);
}

void	*add_node(int x, int y, int z)
{
	double	*point;

	if (!(point = (double *)malloc(sizeof(double) * 3)))
		exit(0);
	point[0] = x;
	point[1] = y;
	point[2] = z;
	return (point);
}

void	add_row(char **array, map_t *map, int add_size)
{
	int		x;
	double	*point;

	if (!(point = (double *)malloc(sizeof(double) * 3)))
		exit(0);
	x = -1;
	while (array[++x])
		map->nodes[x + map->node_size] = add_node(x, map->y, atoi(array[x]));
	if (map->y == 0)
		map->x = add_size;
	map->node_size += add_size;
	map->y++;
}

void	add_to_array(char **array, map_t *map)
{
	int		add_size;

	add_size = array_size(array);
	realloc_array(map, add_size);
	add_row(array, map, add_size);
}