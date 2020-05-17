/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_indexes_edges_augp.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 10:59:19 by mgross        #+#    #+#                 */
/*   Updated: 2020/05/17 23:45:44 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				get_indexes_edges_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->aug_path_links)
		lem_in->aug_path_links =
		ft_lstnew_ptr((void*)lem_in->current_link->id->index, 0);
	else
		ft_lstapp(&lem_in->aug_path_links,
		ft_lstnew_ptr((void*)lem_in->current_link->id->index, 0));
	lem_in->index_copy = lem_in->current_room->id->index;
	lem_in->current_link->capacity = 0;
	if (lem_in->flags & AUGMENT_O)
		ft_printf("\t\tAugment path from %s level %d, to %s level %d\n",
		lem_in->current_room->id->name, lem_in->current_room->level,
		lem_in->current_link->next->id->name,
		lem_in->current_link->next->level);
	lem_in->current_room = lem_in->current_link->next;
	lem_in->temp = lem_in->current_room->links;
	while (((t_edge*)(lem_in->temp->content))->next->id->index !=
	lem_in->index_copy)
		lem_in->temp = lem_in->temp->next;
	lem_in->current_link = ((t_edge*)(lem_in->temp->content));
	ft_lstapp(&lem_in->aug_path_links,
	ft_lstnew_ptr((void*)lem_in->current_link->id->index, 0));
	return (SUCCESS);
}
