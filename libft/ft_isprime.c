/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprime.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 17:37:50 by nstabel        #+#    #+#                */
/*   Updated: 2019/12/27 17:48:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isprime(size_t prime)
{
	size_t		i;

	i = 2;
	while (i <= prime / 2)
	{
		if (prime % i == 0)
			return (0);
		++i;
	}
	return (1);
}
