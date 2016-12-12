#include "fdf.h"

void	free_array(char ***array)
{
	char	**temp;

	temp = *array;
	while (*temp)
		free(*temp++);
	free(*array);
}

void	set_map(map_t *map)
{
	map->node_size = 0;
	map->y = 0;
	map->x = 0;
}

void	set_draw(draw_t *draw, map_t map)
{
	draw->len_x = WINDOW_WIDTH / map.x / 1.2;
	draw->len_y = WINDOW_HEIGHT / map.y / 1.2;
}

void	read_file(char *s, map_t *map)
{
	int			fd;
	int			i;
	char		*line;
	char		**array;
	draw_t		draw;

	fd = open(s, O_RDONLY);
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
	while (++i < map->node_size)
	{
		map->nodes[i][0] = map->nodes[i][0] * draw.len_x + 400.0;
		map->nodes[i][1] = map->nodes[i][1] * draw.len_y - 150.0;
		map->nodes[i][2] = map->nodes[i][2] * 2.0;
	}
}