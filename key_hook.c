/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:14:52 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:15:19 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int		count;

	count = -1;
	while (++count < map->size)
		free(map->n[count]);
	free(map->n);
}

int		quite(void *m)
{
	t_mlx	*mlx;
	t_map	*map;

	mlx = m;
	map = mlx->map;
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_map(map);
	exit(0);
}

int		key_hook(int keycode, void *m)
{
	t_mlx	*mlx;
	t_map	*map;

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
