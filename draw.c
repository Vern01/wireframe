#include <fdf.h>

void	set_draw(draw_t *draw, map_t map)
{
	draw->len_x = WINDOW_WIDTH / map.row / 2;
	draw->len_y = WINDOW_HEIGHT / map.column / 2;
}

void	draw(map_t map, mlx_t mlx)
{
	int		y;
	int		x;
	draw_t	draw;
	cor_t	cor;

	set_draw(&draw, map);
	y = -1;
	while (++y < map.column)
	{
		x = -1;
		while (++x < map.row)
		{
			cor = set_cor(x * draw.len_x, y * draw.len_y, x * draw.len_x + draw.len_x, y * draw.len_y);
			draw_line(cor, mlx, map.iarray[y][x]);
			cor = set_cor(x * draw.len_x, y * draw.len_y, x * draw.len_x, y * draw.len_y + draw.len_y);
			draw_line(cor, mlx, map.iarray[y][x]);
		}
	}
	x = -1;
	while (++x < map.row)
	{
		cor = set_cor(x * draw.len_x, y * draw.len_y, x * draw.len_x + draw.len_x, y * draw.len_y);
		draw_line(cor, mlx, 0);
	}
	y = -1;
	while (++y < map.column)
	{
		cor = set_cor(x * draw.len_x, y * draw.len_y, x * draw.len_x, y * draw.len_y + draw.len_y);
		draw_line(cor, mlx, 0);
	}
}