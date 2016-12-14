/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:04:40 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:04:41 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map_ax(t_map *map)
{
	double	hy;
	double	hx;
	int		count;

	hx = map->n[map->size - 1][0] / 2;
	hy = map->n[map->size - 1][1] / 2;
	count = -1;
	while (++count < map->size)
	{
		map->n[count][0] -= hx;
		map->n[count][1] -= hy;
	}
}
