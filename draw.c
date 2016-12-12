#include "fdf.h"

void	draw(map_t map, mlx_t mlx)
{
	cor_t	cor;
	int		y;
	int		row;

	y = -1;
	row = map.x;
	while (++y < map.node_size - map.x)
	{
		if (y + 1 < row)
		{
			cor = set_cor(map.nodes[y][0], map.nodes[y][1], map.nodes[y + 1][0], map.nodes[y + 1][1]);
			draw_line(cor, mlx);
		}
		else
			row += map.x;
		cor = set_cor(map.nodes[y][0], map.nodes[y][1], map.nodes[y + map.x][0], map.nodes[y + map.x][1]);
		draw_line(cor, mlx);
	}
	y--;
	while (++y < map.node_size - 1)
	{
		cor = set_cor(map.nodes[y][0], map.nodes[y][1], map.nodes[y + 1][0], map.nodes[y + 1][1]);
			draw_line(cor, mlx);
	}
}