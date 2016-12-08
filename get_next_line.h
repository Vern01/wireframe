#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
