#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putstr(char const *s);
char	**ft_strsplit(char const *s, char c);
int		ft_atoi(const char *str);
void	ft_putchar(char c);

#endif