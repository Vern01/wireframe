#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd>
# include <get_next_line.h>
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	camera_s
{
	int		position;
	int		target;
}				camera_t;

typedef struct	mesh_s
{
	void	*vertices;//create an array that contains only three element in 3d space for each void
	int		rotation;
	int		position;
}				mesh_t;

typedef struct	mlx_s
{
	void	*mlx;
	void	*win;
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
	int		swap;
}				line_t;

typedef struct	map_s
{
	int		**iarray;
	int		rows;
	int		columns;
}				map_t;

void    bresenham(cor_t cor, mlx_t mlx);
void	bresenham_p(cor_t cor, mlx_t mlx);
void	draw_line(cor_t cor, mlx_t mlx);
cor_t	set_cor(int x1, int y1, int x2, int y2);
int		**read_file(char *s);

#endif