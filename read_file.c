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
	map->row = 0;
	map->column = 0;
}

void	read_file(char *s, map_t *map)
{
	int			fd;
	char		*line;
	char		**array;

	fd = open(s, O_RDONLY);
	set_map(map);
	while (get_next_line(fd, &line))
	{
		array = ft_strsplit(line, ' ');
		add_to_array(array, map);
		free_array(&array);
		free(line);
	}
}