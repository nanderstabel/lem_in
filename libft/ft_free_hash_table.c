/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_hash_table.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:40:07 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/05 22:50:46 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_elements(t_hash_table *table, void (*free_content)(void *))
{
	t_elem	**elem;
	size_t	i;

	elem = table->elem;
	i = 0;
	while (i < table->size)
	{
		if (elem[i])
		{
			if (table->header_format)
				ft_addr_lstdel(&elem[i]->body_content, ft_freezero);
			else
			{
				free(elem[i]->name);
				free(elem[i]);
			}
			free_content(elem[i]->content);
		}
		++i;
	}
}

static void		free_formats(t_hash_table *table)
{
	ft_lstdel(&table->header_format, ft_freezero);
	ft_lstdel(&table->header_content, ft_freezero);
	ft_lstdel(&table->body_format, ft_freezero);
	ft_addr_lstdel(&table->width, NULL);
}

void			ft_free_hash_table(t_hash_table **table,
					void (*free_content)(void *))
{
	if (!*table)
		return ;
	free_elements(*table, free_content);
	if ((*table)->header_format)
		free_formats(*table);
	if ((*table)->title)
		free((*table)->title);
	free((*table)->elem);
	free(*table);
	*table = NULL;
}
