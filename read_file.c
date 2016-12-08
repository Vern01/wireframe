#include "fdf.h"

	int		**read_file(char *s)
{
	const int	fd;
	int			**iarray;
	char		*line;
	char		*array;

	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		array = ft_strsplit(line, ' ');
		iarray = add_to_array(array);
		free(line);
	}
	return (iarray);
}