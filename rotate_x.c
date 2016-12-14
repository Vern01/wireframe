/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:20:24 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:20:51 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map, double theta)
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
		temp = map->n[i][1];
		map->n[i][1] = map->n[i][1] * vcos - map->n[i][2] * vsin;
		map->n[i][2] = map->n[i][2] * vcos + temp * vsin;
	}
}
