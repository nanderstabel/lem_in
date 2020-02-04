/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 09:37:49 by mgross         #+#    #+#                */
/*   Updated: 2019/02/04 12:23:21 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_math(const char *str, int m)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (result * m);
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

int				ft_atoi(const char *str)
{
	int			result;
	int			i;
	int			m;

	i = 0;
	result = 0;
	m = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		if (ft_strcmp(str, "-2147483648") == 0)
			return (-2147483648);
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = ft_atoi_math(&str[i], m);
	if (result < 0)
		return (result);
	return (result * m);
}
