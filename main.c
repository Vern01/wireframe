/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:19:39 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:19:41 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_map map)
{
	int		i;

	i = -1;
	while (++i < map.size)
		printf("[%f, %f, %f]\n", map.n[i][0], map.n[i][1], map.n[i][2]);
}

int		main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_map	map;

	if (argc == 1)
		return (write(1, "Please give a file name:\n", 25));
	read_file(argv[1], &map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_W + 10, WINDOW_H + 10, "FDF");
	mlx.map = &map;
	rotate_x(&map, 50);
	rotate_y(&map, 30);
	rotate_z(&map, 30);
	draw(map, mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0L, &quite, &mlx);
	mlx_loop(mlx.mlx);
}
