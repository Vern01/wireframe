/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:34:29 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:34:40 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		set_color(t_cor cor, t_map map, int n)
{
	static int		color = -1;
	static int		c_change;
	static int		direction = -1;
	static float	inc;
	static float	current = 0;

	if (color == -1)
	{
		c_change = (0x00FFFFFF - 0x00FF) / map.zmax;
		if (map.iarray[map.y][map.x] < map.iarray[map.y][map.x + 1])
		{
			inc = (map.iarray[map.y][map.x + 1] - map.iarray[map.y][map.x]) / n;
			return (color = 0x00FFFFFF - (c_change * map.iarray[map.y][map.x]));
		}
		else
		{
			inc = (map.iarray[map.y][map.x] - map.iarray[map.y][map.x + 1]) / n;
			direction = 1;
			return (color = 0x00FF + (c_change * map.iarray[map.y][map.x]));
		}
	}
	current += inc;
	if (current >= 1)
		color += c_change * direction;
	return (color);
}

int		set_color(t_cor cor, t_map map, int n)
{
	static int		color = -1;
	static int		c_change;
	static int		direction = -1;
	static float	inc;
	static float	current = 0;

	if (color == -1)
	{
		c_change = (0x00FFFFFF - 0x00FF) / map.zmax;
		if (map.iarray[map.y][map.x] < map.iarray[map.y][map.x + 1])
		{
			inc = (map.iarray[map.y][map.x + 1] - map.iarray[map.y][map.x]) / n;
			return (color = 0x00FFFFFF - (c_change * map.iarray[map.y][map.x]));
		}
		else
		{
			inc = (map.iarray[map.y][map.x] - map.iarray[map.y][map.x + 1]) / n;
			direction = 1;
			return (color = 0x00FF + (c_change * map.iarray[map.y][map.x]));
		}
	}
	current += inc;
	if (current >= 1)
		color += c_change * direction;
	return (color);
}
