/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vertex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:58:36 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/12 17:40:01 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex			*get_vertex(void)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	return (vertex);
}

void				*vertex_columns(t_hash_table *table)
{
	size_t		i;
	size_t		links_width;
	t_elem		*elem;
	char		*links_str;
	t_adlist	*links;

	if (table == NULL)
		return (NULL);
	ft_lstapp(&table->header_content, ft_lstnew("type", 4));
	ft_lstapp(&table->header_content, ft_lstnew("links to:", 9));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	links_width = 5;
	i = 0;
	while (i < table->size)
	{
		if (table->elem[i])
		{
			elem = table->elem[i];
			ft_addr_lstapp(&elem->body_content, ft_addr_lstnew((void *)ft_itoa(((t_vertex *)elem->content)->type)));
			links_str = ft_strnew(0);
			links = ((t_vertex *)(elem->content))->links;
			while (links)
			{
				links_str = ft_append(&links_str, ((t_edge *)(links->address))->id->name);
				links_str = ft_append(&links_str, ", ");
				links = links->next;
			}
			ft_addr_lstapp(&elem->body_content, ft_addr_lstnew((void *)links_str));
			if (links_width < ft_strlen(links_str))
				links_width = ft_strlen(links_str);
		}

		++i;
	}
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)6));
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)(links_width)));
	return (NULL);
}

void				free_vertex(void *content)
{
	t_vertex	*vertex;
	t_adlist	*clean;

	vertex = (t_vertex *)content;
	if (!vertex)
		return ;
	while (vertex->links)
	{
		clean = vertex->links;
		vertex->links = vertex->links->next;
		free(clean);
	}
	free(vertex);
}

void	*ft_hash_table_append(t_hash_table *table, void *(*columns)(t_hash_table *table))
{
	t_adlist	*last_width;

	if (table == NULL || columns == NULL)
		return (NULL);
	last_width = table->width;
	while (last_width->next)
		last_width = last_width->next;
	last_width->address += 2;
	return (columns(table));
}