/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:21:14 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:21:23 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_y(t_map *map, double theta)
{
	double	vsin;
	double	vcos;
	int		i;
	double	temp;

	theta = theta * M_PI / 180.0;
	vsin = sin(theta);
	vcos = cos(theta);
	i = -1;
	while (++i < map->size)
	{
		temp = map->n[i][0];
		map->n[i][0] = map->n[i][0] * vcos - map->n[i][2] * vsin;
		map->n[i][2] = map->n[i][2] * vcos + temp * vsin;
	}
}
