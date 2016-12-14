/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_through_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:27:39 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 16:06:49 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	solve_through_y(t_cor cor, t_line line, t_mlx mlx)
{
	if (cor.y1 > cor.y2)
		swap_points(&cor);
	set_line_info(&line, cor);
	if (line.dx < 0)
		while (cor.y1 <= cor.y2)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1++, 0x00FFFFFF);
			line.eps += line.dx;
			if ((line.eps << 1) <= line.dy * -1)
			{
				cor.x1--;
				line.eps += line.dy;
			}
		}
	else
		while (cor.y1 <= cor.y2)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1++, 0x00FFFFFF);
			line.eps += line.dx;
			if ((line.eps << 1) >= line.dy)
			{
				cor.x1++;
				line.eps -= line.dy;
			}
		}
}
