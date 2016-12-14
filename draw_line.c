/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:11:24 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:12:12 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_line(t_line *line)
{
	line->dx = 0;
	line->dy = 0;
	line->eps = 0;
}

void	draw_line(t_cor cor, t_mlx mlx)
{
	t_line	line;

	set_line(&line);
	if (abs(cor.y1 - cor.y2) > abs(cor.x1 - cor.x2))
		solve_through_y(cor, line, mlx);
	else
		solve_through_x(cor, line, mlx);
}
