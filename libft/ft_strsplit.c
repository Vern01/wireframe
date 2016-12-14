/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:34:22 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 17:11:12 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(const char *s, int start, char del)
{
	int		i;

	i = 0;
	while (s[start++] != '\0' && s[start] != del)
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*re;
	int		i;

	i = 0;
	if (!(re = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= (int)size)
	{
		re[i] = '\0';
		i++;
	}
	return (re);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*re;
	int		i;

	i = 0;
	re = ft_strnew(len + 1);
	if (re == NULL)
		return (NULL);
	len = len + start;
	if (start < ft_strlen(s))
	{
		while (s[start] != '\0' && start < len)
		{
			re[i] = s[start];
			start++;
			i++;
		}
	}
	re[i] = '\0';
	return (re);
}

int		count(char const *s, char c)
{
	int		i;
	int		counter;

	i = -1;
	counter = 1;
	while (s[++i])
		if (s[i] == c && s[i - 1] != c)
			counter++;
	return (counter);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**re;
	int		num;
	int		index;
	int		i;

	num = count(s, c);
	index = 0;
	i = 0;
	if (!(re = (char **)malloc(sizeof(char *) * (num + 1))))
		return (NULL);
	while (index < num)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		re[index] = ft_strsub(s, i, ft_wordlen(s, i, c) + 1);
		i = i + ft_wordlen(s, i, c) + 1;
		index++;
	}
	re[num] = NULL;
	return (re);
}
