/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:58:28 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:01:55 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	realloc_array(t_map *map, int add_size)
{
	double	**new;
	int		y;

	if (!(new = (double **)malloc(sizeof(double *) * (map->size + add_size))))
		exit(0);
	y = -1;
	while (++y < map->size)
		new[y] = map->n[y];
	if (map->size != 0)
		free(map->n);
	map->n = new;
}

int		array_size(char **array)
{
	int		count;

	count = 0;
	while (*array++)
		count++;
	return (count);
}

void	*add_node(int x, int y, int z)
{
	double	*point;

	if (!(point = (double *)malloc(sizeof(double) * 3)))
		exit(0);
	point[0] = x;
	point[1] = y;
	point[2] = z;
	return (point);
}

void	add_row(char **array, t_map *map, int add_size)
{
	int		x;

	x = -1;
	while (array[++x])
		map->n[x + map->size] = add_node(x, map->y, atoi(array[x]));
	if (map->y == 0)
		map->x = add_size;
	map->size += add_size;
	map->y++;
}

void	add_to_array(char **array, t_map *map)
{
	int		add_size;

	add_size = array_size(array);
	realloc_array(map, add_size);
	add_row(array, map, add_size);
}
