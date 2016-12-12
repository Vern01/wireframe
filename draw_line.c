#include "fdf.h"

void	draw_line(cor_t cor, mlx_t mlx)
{
	line_t	line;

    if (abs(cor.y1 - cor.y2) > abs(cor.x1 - cor.x2))
		solve_through_y(cor, line, mlx);
	else
		solve_through_x(cor, line, mlx);
}