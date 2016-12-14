/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:21:48 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 14:15:29 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *p, size_t size, int current_size)
{
	char	*temp;
	int		i;

	temp = p;
	if (!(p = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (++i < current_size)
		p[i] = temp[i];
	free(temp);
	return (p);
}

int		get_char(const int fd, char *c)
{
	static char	buff[BUFF_SIZE];
	static char	*p;
	static int	len = 0;

	if (len == 0)
	{
		if ((len = read(fd, buff, BUFF_SIZE)) < 0)
			return (1);
		p = (char *)&buff;
		if (len == 0)
			return (*c = '\0');
	}
	*c = *p;
	p++;
	len--;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		i;
	char	c;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (get_char(fd, &c))
		return (-1);
	while (c != '\n' && c != '\0' && temp != NULL)
	{
		temp[i++] = c;
		get_char(fd, &c);
		if (i % (BUFF_SIZE + 1) == 0)
			temp = ft_realloc(temp, i + BUFF_SIZE + 1, i);
	}
	if (temp != NULL)
		temp[i] = '\0';
	if (temp == NULL || (c == '\0' && temp[0] == '\0'))
	{
		free(temp);
		return (0);
	}
	*line = temp;
	return (1);
}
