#include <fdf.h>

void	free_iarray(int ***iarray)
{
	int		**temp;
	int		y;

	temp = *iarray;
	y = -1;
	while (temp[++y][0] != -1)
		free(temp[y]);
	free(temp[y]);
	free(*iarray);
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
	draw(map, mlx);
	mlx_loop(mlx.mlx);
}