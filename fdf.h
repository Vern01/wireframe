/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:32:16 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:38:24 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_W 990
# define WINDOW_H 790
# define HALF_WIDTH WINDOW_W / 2
# define HALF_HEIGHT WINDOW_H / 2
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

typedef struct	s_map
{
	double	**n;
	int		size;
	int		y;
	int		x;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_map	*map;
}				t_mlx;

typedef struct	s_cor
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_cor;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		eps;
}				t_line;

typedef struct	s_draw
{
	double	len_x;
	double	len_y;
}				t_draw;

void			add_to_array(char **array, t_map *map);
void			draw(t_map map, t_mlx mlx);
void			draw_line(t_cor cor, t_mlx mlx);
t_cor			set_cor(double x1, double y1, double x2, double y2);
void			read_file(char *s, t_map *map);
int				set_color_x(t_cor cor, t_map map, int n);
void			solve_through_x(t_cor cor, t_line line, t_mlx mlx);
void			solve_through_y(t_cor cor, t_line line, t_mlx mlx);
void			swap_points(t_cor *cor);
void			set_line_info(t_line *line, t_cor cor);
void			rotate_x(t_map *map, double theta);
void			rotate_y(t_map *map, double theta);
void			rotate_z(t_map *map, double theta);
int				key_hook(int keycode, void *m);
int				quite(void *m);
void			center_map_ax(t_map *map);

#endif
