/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash_table_add.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/29 16:05:24 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/03 18:10:47 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_elem	*get_elem(char *name, size_t index, size_t hash, void *content)
{
	t_elem		*elem;

	elem = (t_elem *)malloc(sizeof(t_elem));
	elem->index = index;
	elem->hash = hash;
	elem->name = name;
	elem->content = content;
	return (elem);
}

t_elem			*ft_hash_table_add(t_hash_table *hash_table, char *key,
					void *content)
{
	size_t	i;
	size_t	probe;
	size_t	hash;

	hash = ft_hash(key);
	probe = 0;
	while (probe < hash_table->size)
	{
		i = (hash + probe) % hash_table->size;
		if (hash_table->elem[i])
		{
			if (hash_table->elem[i]->hash == hash){ft_printf("colission!\n");
				if (ft_strequ(hash_table->elem[i]->name, key))
					return (NULL);}
		}
		else
		{
			hash_table->elem[i] = get_elem(key, i, hash, content);
			return (hash_table->elem[i]);
		}
		++probe;
	}
	return (NULL);
}
