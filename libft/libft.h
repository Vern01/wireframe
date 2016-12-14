/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:37:36 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 16:50:07 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putstr(char const *s);
char	**ft_strsplit(char const *s, char c);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
size_t	ft_strlen(const char*s);

#endif
