#include <fdf.h>

int		main(int argc, char *argv[])
{
	mlx_t	mlx;
	int		**iarray;

	if (argc == 1)
		return (write(1, "Please give a file name:\n", 25));
	iarray = read_file(argv[1]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 800, "FDF");
	draw(iarray, mlx);
	mlx_loop(mlx.mlx);		
}