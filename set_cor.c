/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:22:26 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:22:32 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor	set_cor(double x1, double y1, double x2, double y2)
{
	t_cor cor;

	cor.x1 = round(x1 + HALF_WIDTH);
	cor.y1 = round(y1 + HALF_HEIGHT);
	cor.x2 = round(x2 + HALF_WIDTH);
	cor.y2 = round(y2 + HALF_HEIGHT);
	return (cor);
}
