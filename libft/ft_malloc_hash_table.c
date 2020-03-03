/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_hash_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 16:07:55 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/03 16:36:51 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_table	*ft_malloc_hash_table(size_t size, char *title)
{
	t_hash_table	*hash_table;
	size_t			index;

	if (!size)
		return (NULL);
	hash_table = (t_hash_table *)malloc(sizeof(t_hash_table));
	if (hash_table == NULL)
		return (NULL);
	hash_table->elem = (t_elem **)malloc(sizeof(t_elem *) * size);
	if (hash_table->elem == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		hash_table->elem[index] = NULL;
		++index;
	}
	if (title)
		hash_table->title = title;
	hash_table->size = size;
	return (hash_table);
}
