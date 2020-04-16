/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   augmenting_paths.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:00:09 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 16:58:44 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				init_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->level = 0;
	lem_in->round_temp =  0;
	return (SUCCESS);
}

t_bool 				capacity_to_lower_level_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	INDEX_COPY = CURRENT_ROOM_INDEX;
	while (TEMP_LINKS)
	{
		if (CURRENT_ROOM->visited == 1)
		{
			if (lem_in->flags & AUGMENT_O)
				ft_printf("\n\t\tRoom %s with level %d, look for augment path\n", CURRENT_ROOM->id->name, CURRENT_ROOM->level);
			break;
		}
		NEXT_ROOM_TEMP_LINKS = NEXT_ROOM_LINKS;

		while (NEXT_ROOM_TEMP_LINKS)
		{
			if (NEXT_ROOM_TEMP_LINKS_CAPACITY == 0 && NEXT_ROOM_INDEX_CMP == INDEX_COPY)
			{
				break ;
			}
			NEXT_ROOM_TEMP_LINKS = NEXT_ROOM_TEMP_LINKS->next;
		}
		if (NEXT_ROOM_TEMP_LINKS == NULL && TEMP_LINK_CAPACITY == 1 && NEXT_ROOM_LEVEL == (CURRENT_ROOM->level - 1))
		{
			TEMP_LINK_CAPACITY = 0;
			INDEX_COPY = CURRENT_ROOM_INDEX;
			if (lem_in->flags & AUGMENT_O)
					ft_printf("\t\tTravelled from %s level %d visited %d, to %s level %d visited %d\n", CURRENT_ROOM->id->name, CURRENT_ROOM->level, CURRENT_ROOM->visited, NEXT_ROOM->id->name, NEXT_ROOM->level, NEXT_ROOM->visited);
			CURRENT_ROOM = NEXT_ROOM;
			return (SUCCESS);
		}
		TEMP_LINKS = TEMP_LINKS->next;
	}
	return (FAIL);// Deze kan waarschijnlijk weg
}

t_bool				get_indexes_edges_augp(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->aug_path_links)
		lem_in->aug_path_links =
		ft_addr_lstnew((void*)lem_in->current_link->id->index);
	else
		ft_addr_lstapp(&lem_in->aug_path_links,
		ft_addr_lstnew((void*)lem_in->current_link->id->index));
	lem_in->index_copy = lem_in->current_room->id->index;
	lem_in->current_link->capacity = 0;
	if (lem_in->flags & AUGMENT_O)
		ft_printf("\t\tAugment path from %s level %d, to %s level %d\n",
		lem_in->current_room->id->name, lem_in->current_room->level,
		lem_in->current_link->next->id->name,
		lem_in->current_link->next->level);
	lem_in->current_room = lem_in->current_link->next;
	lem_in->temp = lem_in->current_room->links;
	while (((t_edge*)(lem_in->temp->address))->next->id->index !=
	lem_in->index_copy)
		lem_in->temp = lem_in->temp->next;
	lem_in->current_link = ((t_edge*)(lem_in->temp->address));
	ft_addr_lstapp(&lem_in->aug_path_links,
	ft_addr_lstnew((void*)lem_in->current_link->id->index));
	return (SUCCESS);
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

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_install_machine_bfs][SUCCESS] = s_init_augp;
	TRANSITIONS[s_init_augp][SUCCESS] = s_capacity_from_sink_augp;
	TRANSITIONS[s_capacity_from_sink_augp][SUCCESS] = s_capacity_to_lower_level_augp;
	TRANSITIONS[s_capacity_from_sink_augp][FAIL] = s_clear_rooms_on_graph_augp;
	TRANSITIONS[s_capacity_to_lower_level_augp][SUCCESS] = s_current_room_sink_augp;
	TRANSITIONS[s_capacity_to_lower_level_augp][FAIL] = s_check_augment_path_augp;
	TRANSITIONS[s_current_room_sink_augp][SUCCESS] = s_capacity_from_sink_augp;
	TRANSITIONS[s_current_room_sink_augp][FAIL] = s_capacity_to_lower_level_augp;
	TRANSITIONS[s_check_augment_path_augp][FAIL] = s_clear_rooms_on_graph_augp; // <<< volgens mij kan er geen fail zijn
	TRANSITIONS[s_check_augment_path_augp][SUCCESS] = s_get_indexes_edges_augp;
	TRANSITIONS[s_get_indexes_edges_augp][SUCCESS] = s_clear_rooms_on_graph_augp;
	TRANSITIONS[s_clear_rooms_on_graph_augp][SUCCESS] = s_clear_links_on_graph_augp;
	TRANSITIONS[s_clear_links_on_graph_augp][SUCCESS] = s_print_tables_augp;
	TRANSITIONS[s_print_tables_augp][FAIL] = s_uninstall_machine_augp;
	TRANSITIONS[s_print_tables_augp][SUCCESS] = s_uninstall_machine_augp;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_augp] = NULL;
	EVENTS[s_init_augp] = init_augp;
	EVENTS[s_capacity_from_sink_augp] = capacity_from_sink_augp;
	EVENTS[s_capacity_to_lower_level_augp] = capacity_to_lower_level_augp;
	EVENTS[s_check_augment_path_augp] = check_augment_path_augp;
	EVENTS[s_get_indexes_edges_augp] = get_indexes_edges_augp;
	EVENTS[s_current_room_sink_augp] = current_room_sink_augp;
	EVENTS[s_clear_rooms_on_graph_augp] = clear_rooms_on_graph_augp;
	EVENTS[s_clear_links_on_graph_augp] = clear_links_on_graph_augp;
	EVENTS[s_print_tables_augp] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_augp);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool					augmenting_paths(t_project *lem_in)
{
	t_machine	*machine;

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	lem_in->loop++;//Added this to experiment with breaking out of the loop...
	if (lem_in->round_temp == 0 || lem_in->loop == 12)// ...after n times
	{
		ft_addr_lstdel(&lem_in->aug_path_links);
		return (FAIL);
	}
	return (SUCCESS);
}
