/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:23:30 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 16:25:05 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_map m, t_mlx mlx)
{
	t_cor	cor;
	int		y;
	int		row;

	y = -1;
	row = m.x;
	while (++y < m.size - m.x)
	{
		if (y + 1 < row)
		{
			cor = set_cor(m.n[y][0], m.n[y][1], m.n[y + 1][0], m.n[y + 1][1]);
			draw_line(cor, mlx);
		}
		else
			row += m.x;
		cor = set_cor(m.n[y][0], m.n[y][1], m.n[y + m.x][0], m.n[y + m.x][1]);
		draw_line(cor, mlx);
	}
	y--;
	while (++y < m.size - 1)
	{
		cor = set_cor(m.n[y][0], m.n[y][1], m.n[y + 1][0], m.n[y + 1][1]);
		draw_line(cor, mlx);
	}
}
