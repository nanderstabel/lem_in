/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 14:00:18 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/19 14:41:40 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					*get_edge(void)
{
	t_edge		*edge;

	edge = (t_edge *)ft_memalloc(sizeof(t_edge));
	edge->capacity = 1;
	return (edge);
}

static void				add_body_content(t_hash_table *table)
{
	size_t		i;
	t_elem		*elem;

	i = 0;
	while (i < table->size)
	{
		if (table->elem[i])
		{
			elem = table->elem[i];
			ft_lstapp(&elem->body_content, \
				ft_lstnew_ptr(ft_itoa(((t_edge *)elem->content)->capacity), 0));
			ft_lstapp(&elem->body_content, \
				ft_lstnew_ptr(ft_strdup(((t_edge *)\
					(elem->content))->next->id->name), 0));
		}
		++i;
	}
}

void					*edge_columns(t_hash_table *table)
{
	if (table == NULL)
		return (NULL);
	ft_lstapp(&table->header_content, ft_lstnew("capacity", 8));
	ft_lstapp(&table->header_content, ft_lstnew("next", 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	add_body_content(table);
	ft_lstapp(&table->width, ft_lstnew_ptr((void *)10, 0));
	ft_lstapp(&table->width, ft_lstnew_ptr((void *)10, 0));
	return (table);
}

void					free_edge(void *content)
{
	t_edge	*edge;

	if (!content)
		return ;
	edge = (t_edge *)content;
	free(edge);
}
