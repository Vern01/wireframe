#ifndef FDF_H
# define FDF_H
# define WINDOW_WIDTH 990
# define WINDOW_HEIGHT 790
# define HALF_WIDTH WINDOW_WIDTH / 2
# define HALF_HEIGHT WINDOW_HEIGHT / 2
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	map_s
{
	double	**nodes;
	int		node_size;
	int		y;
	int		x;
}				map_t;

typedef struct	mlx_s
{
	void	*mlx;
	void	*win;
	map_t	*map;
}				mlx_t;

typedef struct	cor_s
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				cor_t;

typedef struct	line_s
{
	int		dx;
	int		dy;
	int		eps;
}				line_t;

typedef struct	draw_s
{
	double	len_x;
	double	len_y;
}				draw_t;

void	add_to_array(char **array, map_t *map);
void	draw(map_t map, mlx_t mlx);
void	draw_line(cor_t cor, mlx_t mlx);
cor_t	set_cor(double x1, double y1, double x2, double y2);
void	read_file(char *s, map_t *map);
int		set_color_x(cor_t cor, map_t map, int n);
void	solve_through_x(cor_t cor, line_t line, mlx_t mlx);
void	solve_through_y(cor_t cor, line_t line, mlx_t mlx);
void    swap_points(cor_t *cor);
void	set_line_info(line_t *line, cor_t cor);
void	rotate_x(map_t *map, double theta);
void	rotate_y(map_t *map, double theta);
void	rotate_z(map_t *map, double theta);
int		key_hook(int keycode, void *m);
int		quite(void *m);
void    center_map_ax(map_t *map);

#endif