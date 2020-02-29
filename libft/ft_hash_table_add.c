/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash_table_add.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 16:05:24 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/29 16:34:49 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_hash_table_add(t_hash_table *hash_table, char *key,
			t_hashequ hashequ, t_get_elem get_elem)
{
	size_t	i;
	size_t	probe;
	size_t	hash;

	hash = ft_hash(key);
	probe = 0;
	while (probe < hash_table->size)
	{
		i = (hash + probe) % hash_table->size;
		if (hash_table->elem[i] == NULL)
		{
			hash_table->elem[i] = get_elem(key, i, hash);
			return (hash_table->elem[i]);
		}
		else if (hashequ(hash_table->elem[i], hash))
			return (NULL);
		++probe;
	}
	return (NULL);
}
