/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_primetab.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 17:38:48 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/12 14:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		*ft_primetab(size_t n)
{
	size_t		*tab;
	size_t		prime;
	size_t		i;

	if (!n)
		return (NULL);
	tab = (size_t *)malloc(sizeof(size_t) * (n + 1));
	tab[0] = 0;
	tab[1] = 2;
	prime = 3;
	i = 2;
	while (i <= n)
	{
		while (!ft_isprime(prime))
			++prime;
		tab[i] = prime;
		prime += 2;
		++i;
	}
	return (tab);
}
