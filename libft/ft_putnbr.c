/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 08:42:30 by mgross         #+#    #+#                */
/*   Updated: 2019/01/31 14:15:27 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		n = n * -1;
	}
	if (n < 10 && n >= 0)
	{
		ft_putchar(n + 48);
	}
	else if (n > 0)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}
