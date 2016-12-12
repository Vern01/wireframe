#include "fdf.h"
#include <stdio.h>

void	print_map(map_t map)
{
	int		i;

	i = -1;
	while (++i < map.node_size)
		printf("[%d, %d, %d]\n", map.nodes[i][0], map.nodes[i][1], map.nodes[i][2]);
}

int		main(int argc, char *argv[])
{
	mlx_t	mlx;
	map_t	map;

	if (argc == 1)
		return (write(1, "Please give a file name:\n", 25));
	read_file(argv[1], &map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH + 10, WINDOW_HEIGHT + 10, "FDF");
	rotate_x(&map, 50);
	rotate_y(&map, 15);
	rotate_z(&map, 30);
	draw(map, mlx);
	mlx_loop(mlx.mlx);
	print_map(map);
}