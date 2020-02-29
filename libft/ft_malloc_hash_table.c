/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_hash_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 16:07:55 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/29 16:12:01 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_table	*ft_malloc_hash_table(size_t size)
{
	t_hash_table	*hash_table;
	size_t			index;

	hash_table = (t_hash_table *)malloc(sizeof(t_hash_table));
	if (hash_table == NULL)
		return (NULL);
	hash_table->elem = (void **)malloc(sizeof(void *) * size);
	if (hash_table->elem == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		hash_table->elem[index] = NULL;
		++index;
	}
	hash_table->size = size;
	return (hash_table);
}
