/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vertex_columns.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:27:12 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/15 17:33:06 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			add_body_content3(t_elem *elem, t_adlist *links, \
	size_t links_width)
{
	char		*links_str;

	links_str = ft_strnew(0);
	links = ((t_vertex *)(elem->content))->links;
	while (links)
	{
		links_str = ft_append(&links_str, \
			((t_edge *)(links->address))->id->name);
		links_str = ft_append(&links_str, ", ");
		links = links->next;
	}
	ft_lstadd(&elem->misc, ft_lstnew(links_str, ft_strlen(links_str)));
	free(links_str);
	ft_addr_lstapp(&elem->body_content, ft_addr_lstnew(elem->misc->content));
	if (links_width < ft_strlen(links_str))
		links_width = ft_strlen(links_str);
}

static void			add_body_content2(t_elem *elem)
{
	char		*type_str;

	if (((t_vertex *)(elem->content))->type == 1)
		type_str = ft_strdup("Source");
	else if (((t_vertex *)(elem->content))->type == 2)
		type_str = ft_strdup("Sink");
	else
		type_str = ft_strdup("0");
	ft_lstadd(&elem->misc, ft_lstnew(type_str, ft_strlen(type_str)));
	free(type_str);
	ft_addr_lstapp(&elem->body_content, ft_addr_lstnew(elem->misc->content));
	type_str = ft_itoa(((t_vertex *)(elem->content))->level);
	ft_lstadd(&elem->misc, ft_lstnew(type_str, ft_strlen(type_str)));
	free(type_str);
	ft_addr_lstapp(&elem->body_content, ft_addr_lstnew(elem->misc->content));
	if (((t_vertex *)(elem->content))->visited)
		type_str = ft_strdup("Yes");
	else
		type_str = ft_strdup("No");
	ft_lstadd(&elem->misc, ft_lstnew(type_str, ft_strlen(type_str)));
	free(type_str);
	ft_addr_lstapp(&elem->body_content, ft_addr_lstnew(elem->misc->content));
}

static void			add_body_content(t_hash_table *table, t_adlist *links, \
	size_t links_width)
{
	t_elem		*elem;
	size_t		i;

	i = 0;
	while (i < table->size)
	{
		if (table->elem[i])
		{
			elem = table->elem[i];
			add_body_content2(elem);
			add_body_content3(elem, links, links_width);
		}
		++i;
	}
}

void				*vertex_columns(t_hash_table *table)
{
	size_t		links_width;
	t_adlist	*links;

	links = NULL;
	if (table == NULL)
		return (NULL);
	ft_lstapp(&table->header_content, ft_lstnew("type", 4));
	ft_lstapp(&table->header_content, ft_lstnew("level", 5));
	ft_lstapp(&table->header_content, ft_lstnew("visited", 7));
	ft_lstapp(&table->header_content, ft_lstnew("links to:", 9));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->header_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	ft_lstapp(&table->body_format, ft_lstnew(table->format, 4));
	links_width = 5;
	add_body_content(table, links, links_width);
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)8));
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)7));
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)9));
	ft_addr_lstapp(&table->width, ft_addr_lstnew((void *)(links_width)));
	return (table);
}
