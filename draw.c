#include <fdf.h>

void	set_draw(draw_t *draw, map_t map)
{
	draw->len_x = WINDOW_WIDTH / map.row;
	draw->len_y = WINDOW_HEIGHT / map.column;
}

void	draw(map_t map, mlx_t mlx)
{
	int		y;
	int		x;
	draw_t	draw;

	set_draw(&draw);
	y = -1;
	while (++y < map->column)
	{
		x = -1;
		while (++x < map->row)
		{
			set_cor(x * draw.len_x, y, x * draw.len_x + draw.len_x, y);
			draw_line(cor, mlx);
		}
		set_cor(x, y * draw.len_y, x, y * draw.len_y + draw.len_y);
		draw_line(cor, mlx);
	}
}