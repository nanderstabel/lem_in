/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 10:06:46 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/02 19:46:34 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_hash(char *key)
{
	size_t	index;
	size_t	hash;

	index = 0;
	hash = 0;
	while (key[index])
	{
		hash += (key[index] * key[index]) * (index + 1);
		++index;
	}
	hash *= index;
	return (hash);
}
