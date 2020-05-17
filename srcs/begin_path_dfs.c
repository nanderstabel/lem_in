/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   begin_path_dfs.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:29:24 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 23:25:28 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				sort_links_lists(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->index = 0;
	lem_in->source->level = __INT_MAX__;
	while (lem_in->index < lem_in->all_rooms->size)
	{
		lem_in->current_room = lem_in->all_rooms->elem[lem_in->index]->content;
		ft_lstsrt(&lem_in->current_room->links, sort_by_level);
		lem_in->current_room->selected = lem_in->current_room->links;
		++lem_in->index;
	}
	return (SUCCESS);
}

t_bool				start_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->current_room = lem_in->source;
	lem_in->current_path = ft_lstnew_ptr((void *)lem_in->current_room, 0);
	lem_in->index = 0;
	if (!lem_in->current_room || !lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tStart path\n");
	return (SUCCESS);
}

t_bool				find_next_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (lem_in->current_room->selected)
	{
		lem_in->temp = lem_in->current_room->selected;
		if (((t_edge*)(lem_in->temp->content))->capacity && ((t_edge*)\
			(lem_in->temp->content))->next->level < lem_in->current_room->level)
			if (!((t_edge*)(lem_in->temp->content))->next->visited)
				return (SUCCESS);
		lem_in->current_room->selected = lem_in->current_room->selected->next;
	}
	return (FAIL);
}

t_bool				backtrack_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->current_room == lem_in->source)
		return (FAIL);
	lem_in->current_room->visited = 0;
	lem_in->current_room = (t_vertex *)lem_in->current_path->next->content;
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tBacktracked to: %s\n", lem_in->current_room->id->name);
	return (SUCCESS);
}
