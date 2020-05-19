/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vertex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:58:36 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/19 17:13:49 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex			*get_vertex(void)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	return (vertex);
}

void				free_vertex(void *content)
{
	t_vertex	*vertex;
	t_list		*clean;

	if (!content)
		return ;
	vertex = (t_vertex *)content;
	while (vertex->links)
	{
		clean = vertex->links;
		vertex->links = vertex->links->next;
		free(clean);
	}
	free(vertex);
}

char				*vertex_name(void *item)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)item;
	return (vertex->id->name);
}
