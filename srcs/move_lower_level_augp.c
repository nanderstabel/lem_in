/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_lower_level_augp.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 10:53:18 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/17 11:30:30 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_adlist		*check_next_room_links(t_project *lem_in)
{
	while (lem_in->temp_que_list)
	{
		if (((t_edge*)(lem_in->temp_que_list->address))->capacity == 0 &&
		((t_edge*)(lem_in->temp_que_list->address))->next->id->index ==
		lem_in->current_room->id->index)
		{
			break ;
		}
		lem_in->temp_que_list = lem_in->temp_que_list->next;
	}
	return (lem_in->temp_que_list);
}

static void			assign_vars(t_project *lem_in)
{
	((t_edge*)(lem_in->temp->address))->capacity = 0;
	lem_in->index_copy = lem_in->current_room->id->index;
	if (lem_in->flags & AUGMENT_O)
		ft_printf("\t\tTravelled from %s level %d visited %d, to %s level \
%d visited %d\n", lem_in->current_room->id->name, lem_in->current_room->level,
			lem_in->current_room->visited, ((t_edge*)(lem_in->temp->address))
			->next->id->name, ((t_edge*)(lem_in->temp->address))->next->level,
			((t_edge*)(lem_in->temp->address))->next->visited);
	lem_in->current_room = ((t_edge*)(lem_in->temp->address))->next;
}

t_bool				move_lower_level_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->temp = lem_in->current_room->links;
	while (lem_in->temp)
	{
		if (lem_in->current_room->visited == 1)
		{
			if (lem_in->flags & AUGMENT_O)
				ft_printf("\n\t\tRoom %s with level %d, look for augment \
path\n", lem_in->current_room->id->name, lem_in->current_room->level);
			break ;
		}
		lem_in->temp_que_list = ((t_edge*)(lem_in->temp->address))->next->links;
		check_next_room_links(lem_in);
		if (lem_in->temp_que_list == NULL &&
		((t_edge*)(lem_in->temp->address))->capacity == 1 &&
		((t_edge*)(lem_in->temp->address))->next->level ==
		(lem_in->current_room->level - 1))
		{
			assign_vars(lem_in);
			return (SUCCESS);
		}
		lem_in->temp = lem_in->temp->next;
	}
	return (FAIL);
}

t_bool				current_room_sink_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->current_room == lem_in->sink)
	{
		if (lem_in->flags & AUGMENT_O)
			ft_printf("\t\tSink reached\n");
		return (SUCCESS);
	}
	return (FAIL);
}
