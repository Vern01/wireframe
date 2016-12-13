#include "fdf.h"

void    center_map_ax(map_t *map)
{
    double	hy;
    double	hx;
    int		count;

    hx = map->nodes[map->node_size - 1][0] / 2;
    hy = map->nodes[map->node_size - 1][1] / 2;
	count = -1;
	while (++count < map->node_size)
	{
		map->nodes[count][0] -= hx;
		map->nodes[count][1] -= hy;
	}
}