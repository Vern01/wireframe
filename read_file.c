/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:33:51 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:36:33 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(char ***array)
{
	char	**temp;

	temp = *array;
	while (*temp)
		free(*temp++);
	free(*array);
}

void	set_map(t_map *map)
{
	map->size = 0;
	map->y = 0;
	map->x = 0;
}

void	set_draw(t_draw *draw, t_map map)
{
	draw->len_x = WINDOW_W / map.x / 1.2;
	draw->len_y = WINDOW_H / map.y / 1.2;
}

void	read_file(char *s, t_map *map)
{
	int			fd;
	int			i;
	char		*line;
	char		**array;
	t_draw		draw;

	if ((fd = open(s, O_RDONLY)) == -1)
		exit(write(1, "File does not exist.\n", 22));
	set_map(map);
	while (get_next_line(fd, &line))
	{
		array = ft_strsplit(line, ' ');
		add_to_array(array, map);
		free_array(&array);
		free(line);
	}
	set_draw(&draw, *map);
	i = -1;
	while (++i < map->size)
	{
		map->n[i][0] = map->n[i][0] * draw.len_x;
		map->n[i][1] = map->n[i][1] * draw.len_y;
		map->n[i][2] = map->n[i][2] * 3.0;
	}
	center_map_ax(map);
}
