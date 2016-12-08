#include "fdf.h"

void      set_line_info(line_t *line, cor_t cor)
{
    line->dx = cor.x2 - cor.x1;
    line->dy = cor.y2 - cor.y1;
    line->eps = 0;
    line->swap = 0;
}

void    swap_points(cor_t *cor)
{
    int     temp;

    temp = cor->x1;
    cor->x1 = cor->x2;
    cor->x2 = temp;
    temp = cor->y1;
    cor->y1 = cor->y2;
    cor->y2 = temp;
}

void	draw_line(cor_t cor, mlx_t mlx)
{
	line_t	line;

    set_line_info(&line, cor);
    if (abs(cor.y1 - cor.y2) > abs(cor.x1 - cor.x2))
		solve_through_y(cor, line, mlx);
	else
		solve_through_x(cor, line, mlx);
}