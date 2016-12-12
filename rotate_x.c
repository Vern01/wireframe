#include "fdf.h"

void	rotate_x(map_t *map, double theta)
{
	double	vsin;
	double	vcos;
	int		i;
	double	temp;

	theta = theta * M_PI / 180.0;
	vsin = sin(theta);
	vcos = cos(theta);
	i = -1;
	while (++i < map->node_size)
	{
		temp = map->nodes[i][1];
		map->nodes[i][1] = map->nodes[i][1] * vcos - map->nodes[i][2] * vsin;
		map->nodes[i][2] = map->nodes[i][2] * vcos +  temp * vsin;
	}
}