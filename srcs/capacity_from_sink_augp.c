/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   capacity_from_sink_augp.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 16:27:36 by mgross        #+#    #+#                 */
/*   Updated: 2020/04/19 09:44:29 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				init_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->level = 0;
	lem_in->round_temp = 0;
	return (SUCCESS);
}

static void			print_debug(t_project *lem_in)
{
	ft_printf("\t\tTravelled from %s level %d visited %d, to %s level %d \
visited %d\n", lem_in->current_room->id->name, lem_in->current_room->level,
	lem_in->current_room->visited, ((t_edge*)(lem_in->temp->address))
	->next->id->name, ((t_edge*)(lem_in->temp->address))->next->level,
	((t_edge*)(lem_in->temp->address))->next->visited);
}

static int			check_next_room_links(t_project *lem_in)
{
	while (lem_in->temp_que_list)
	{
		if (((t_edge*)(lem_in->temp_que_list->address))->capacity == 1 &&
		((t_edge*)(lem_in->temp_que_list->address))->next->id->index ==
		lem_in->current_room->id->index &&
		((t_edge*)(lem_in->temp->address))->next->level != 0)
		{
			lem_in->level++;
			((t_edge*)(lem_in->temp->address))->capacity = 0;
			if (lem_in->flags & AUGMENT_O)
				print_debug(lem_in);
			lem_in->current_room = ((t_edge*)(lem_in->temp->address))->next;
			return (SUCCESS);
		}
		lem_in->temp_que_list = lem_in->temp_que_list->next;
	}
	return (FAIL);
}

t_bool				capacity_from_sink_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & AUGMENT_O)
		ft_printf("\t\tStart path from Sink (%s) level %d\n",
		lem_in->sink->id->name, lem_in->sink->level);
	lem_in->current_room = lem_in->sink;
	lem_in->temp = lem_in->sink->links;
	while (lem_in->temp)
	{
		lem_in->temp_que_list = ((t_edge*)(lem_in->temp->address))->next->links;
		if (check_next_room_links(lem_in))
			return (SUCCESS);
		lem_in->temp = lem_in->temp->next;
	}
	if (lem_in->flags & AUGMENT_O)
		ft_printf("\t\tNo capacity avalible from Sink. End algorithm\n");
	return (FAIL);
}
