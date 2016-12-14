/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:05:27 by vivan-de          #+#    #+#             */
/*   Updated: 2016/12/14 15:35:24 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				neg;
	unsigned int	val;

	neg = 0;
	val = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str > 47 && *str < 58)
	{
		val = (val * 10) + (*str - '0');
		str++;
	}
	if (neg)
		return (-val);
	else
		return (val);
}
