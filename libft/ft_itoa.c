/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 11:37:35 by mgross         #+#    #+#                */
/*   Updated: 2019/02/04 13:27:08 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_static_malloc(int sign, int b)
{
	char	*str;

	str = ft_strnew(sign + b);
	if (str == NULL)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	str[sign + b] = '\0';
	return (str);
}

static int		ft_base_10(int n)
{
	int		b;
	long	r;

	r = 1;
	b = 1;
	while (r <= n)
	{
		r = r * 10;
		b++;
	}
	return (b - 1);
}

static char		*ft_itoa_math(char *str, int n, int i, int sign)
{
	while (i >= 0 + sign)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;
	int		b;

	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		sign = 1;
		n = n * -1;
	}
	b = ft_base_10(n);
	str = ft_static_malloc(sign, b);
	if (str == NULL)
		return (NULL);
	i = b + sign - 1;
	ft_itoa_math(str, n, i, sign);
	return (str);
}
