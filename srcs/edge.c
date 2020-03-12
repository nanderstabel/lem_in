/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 14:00:18 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/12 15:56:21 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				*get_edge(void)
{
	t_edge		*edge;

	edge = (t_edge *)ft_memalloc(sizeof(t_edge));
	edge->id = NULL;
	edge->capacity = 0;
	edge->back = NULL;
	edge->forward = NULL;
	return (edge);
}

void				*edge_columns(t_hash_table *table)
{
	size_t		i;
	t_elem		*elem;
	//size_t		back_width;
	//size_t		forward_width;

	if (table == NULL)
		return (NULL);
	ft_lstapp(&table->header_content, ft_lstnew("capacity", 8));
	ft_lstapp(&table->header_content, ft_lstnew("back", 4));
	ft_lstapp(&table->header_content, ft_lstnew("forward", 7));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));

	i = 0;
	while (i < table->size)
	{
		if (table->elem[i])
		{
			elem = table->elem[i];
			ft_addr_lstapp(&elem->body_content, ft_addr_lstnew(ft_itoa(((t_edge *)elem->content)->capacity)));
			ft_addr_lstapp(&elem->body_content, ft_addr_lstnew(ft_strdup(((t_edge *)(elem->content))->back->id->name)));
			ft_addr_lstapp(&elem->body_content, ft_addr_lstnew(ft_strdup(((t_edge *)(elem->content))->forward->id->name)));
		}
		++i;
	}
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)10));
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)10));
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)10));
	return (NULL);
}

void				free_edge(void *content)
{
	t_edge	*edge;

	edge = (t_edge *)content;
	if (!edge)
		return ;
	free(edge);
}
