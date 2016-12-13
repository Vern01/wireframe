#include "fdf.h"


void	free_map(map_t *map)
{
	int		count;

	count = -1;
	while (++count < map->node_size)
		free(map->nodes[count]);
	free(map->nodes);
}

int		quite(void *m)
{
	mlx_t	*mlx;
	map_t	*map;

	mlx = m;
	map = mlx->map;
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_map(map);
	exit(0);
}

int		key_hook(int keycode, void *m)
{
	mlx_t	*mlx;
	map_t	*map;

	mlx = m;
	map = mlx->map;
	if (keycode == 53)
	{
		free_map(map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}