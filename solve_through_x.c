/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_through_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:27:00 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 16:07:16 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	solve_through_x(t_cor cor, t_line line, t_mlx mlx)
{
	if (cor.x1 > cor.x2)
		swap_points(&cor);
	set_line_info(&line, cor);
	if (line.dy < 0)
		while (cor.x1 <= cor.x2)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, cor.x1++, cor.y1, 0x00FFFFFF);
			line.eps += line.dy;
			if ((line.eps << 1) <= line.dx * -1)
			{
				cor.y1--;
				line.eps += line.dx;
			}
		}
	else
		while (cor.x1 <= cor.x2)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, cor.x1++, cor.y1, 0x00FFFFFF);
			line.eps += line.dy;
			if ((line.eps << 1) >= line.dx)
			{
				cor.y1++;
				line.eps -= line.dx;
			}
		}
}
