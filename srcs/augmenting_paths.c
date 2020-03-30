/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   augmenting_paths.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:00:09 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/30 21:49:21 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				capacity_from_source_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	TEMP_LINKS = SOURCE->links;
	while (TEMP_LINKS)
	{
		if (TEMP_LINK_CAPACITY == 1)
		{
			TEMP_LINK_CAPACITY = 0;
			CURRENT_ROOM = NEXT_ROOM;
			return (SUCCESS);
		}
		TEMP_LINKS = TEMP_LINKS->address;
	}
	return (FAIL);
}

t_bool 				capacity_to_lower_level_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	while (TEMP_LINKS)
	{
		if (TEMP_LINK_CAPACITY == 1 && NEXT_ROOM_LEVEL == CURRENT_ROOM->level - 1)
		{
			TEMP_LINK_CAPACITY = 0;
			INDEX_COPY = CURRENT_ROOM_INDEX;
			CURRENT_ROOM = NEXT_ROOM;
			return (SUCCESS);
		}
		TEMP_LINKS = TEMP_LINKS->next;
	}
	return (FAIL);// Deze kan waarschijnlijk weg
}

t_bool				capacity_to_higher_level_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	while (TEMP_LINKS)
	{
		if (TEMP_LINK_CAPACITY == 1 && NEXT_ROOM_LEVEL == CURRENT_ROOM->level + 1 \
		&& NEXT_ROOM_INDEX != INDEX_COPY)
		{
			return (SUCCESS);
		}
		TEMP_LINKS = TEMP_LINKS->next;
	}
	return (FAIL);
}

t_bool				capacity_away_from_augment_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	INDEX_COPY = CURRENT_ROOM_INDEX;
	while (TEMP_LINKS)
	{
		if (TEMP_LINK_CAPACITY == 1)
		{
			NEXT_ROOM_TEMP_LINKS = NEXT_ROOM_LINKS;
			while (NEXT_ROOM_TEMP_LINKS)
			{
				if (NEXT_ROOM_TEMP_LINKS_CAPACITY == 0 && NEXT_ROOM_INDEX_CMP == INDEX_COPY)
					break ;
				NEXT_ROOM_TEMP_LINKS = NEXT_ROOM_TEMP_LINKS->next;
			}
			if (NEXT_ROOM_TEMP_LINKS == NULL)
			{
				CURRENT_EDGE_INDEX = 0;
				CURRENT_ROOM = NEXT_ROOM;
				return (SUCCESS);
			}
		}
		TEMP_LINKS = TEMP_LINKS->next;
	}
	return (FAIL);
}

t_bool				get_indexes_edges_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	INDEX_COPY = CURRENT_ROOM_INDEX;
	if (!QUE)
	{
		QUE = ft_addr_lstnew((void*)VERTEX_INDEX);
		ROUND_NR++;
	}
	else
		ft_addr_lstapp(&QUE, ft_addr_lstnew((void*)VERTEX_INDEX));
	CURRENT_EDGE_INDEX = 0;
	CURRENT_ROOM = NEXT_ROOM;
	TEMP_LINKS = CURRENT_ROOM->links;
	while (NEXT_ROOM_INDEX != INDEX_COPY)
	{
		TEMP_LINKS = TEMP_LINKS->next;
	}
	CURRENT_EDGE = TEMP_LINKS;
	ft_addr_lstapp(&QUE, ft_addr_lstnew((void*)CURRENT_EDGE_INDEX));
	return (SUCCESS);
}

t_bool				check_capcity_to_lower_level_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	while (TEMP_LINKS)
	{
		if (TEMP_LINK_CAPACITY == 1 && NEXT_ROOM_LEVEL == CURRENT_ROOM->level - 1)
			return (SUCCESS);
		TEMP_LINKS = TEMP_LINKS->next;
	}
	return (FAIL);
}

t_bool				current_room_sink_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (CURRENT_ROOM == SINK)
		return (SUCCESS);
	return (FAIL);
}

t_bool				current_room_source_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (CURRENT_ROOM == SOURCE)
		return (SUCCESS);
	return (FAIL);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_install_machine_bfs][SUCCESS] = s_capacity_from_source_augp;
	TRANSITIONS[s_capacity_from_source_augp][SUCCESS] = s_capacity_to_lower_level_augp;
	TRANSITIONS[s_capacity_from_source_augp][FAIL] = s_print_tables_augp; // EINDE
	TRANSITIONS[s_capacity_to_lower_level_augp][SUCCESS] = s_current_room_sink_augp;
	TRANSITIONS[s_capacity_to_lower_level_augp][FAIL] = s_capacity_to_higher_level_augp;
	TRANSITIONS[s_current_room_sink_augp][SUCCESS] = s_capacity_from_source_augp;
	TRANSITIONS[s_current_room_sink_augp][FAIL] = s_capacity_to_lower_level_augp;
	// TRANSITIONS[s_capacity_to_higher_level_augp][FAIL] = s_edge_list_remain_bfs; <<< volgens mij kan er geen fail zijn
	TRANSITIONS[s_capacity_to_higher_level_augp][SUCCESS] = s_get_indexes_edges_augp;
	TRANSITIONS[s_get_indexes_edges_augp][SUCCESS] = s_current_room_source_augp;
	TRANSITIONS[s_current_room_source_augp][FAIL] = s_check_capcity_to_lower_level_augp;
	TRANSITIONS[s_current_room_source_augp][SUCCESS] = s_capacity_from_source_augp;
	TRANSITIONS[s_check_capcity_to_lower_level_augp][FAIL] = s_capacity_away_from_augment_augp;
	TRANSITIONS[s_check_capcity_to_lower_level_augp][SUCCESS] = s_capacity_to_lower_level_augp;
	TRANSITIONS[s_capacity_away_from_augment_augp][FAIL] = s_capacity_to_higher_level_augp;
	TRANSITIONS[s_capacity_away_from_augment_augp][SUCCESS] = s_check_capcity_to_lower_level_augp;
	TRANSITIONS[s_print_tables_augp][FAIL] = s_uninstall_machine_augp;
	TRANSITIONS[s_print_tables_augp][SUCCESS] = s_uninstall_machine_augp;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_augp] = NULL;
	EVENTS[s_capacity_from_source_augp] = capacity_available_bfs;
	EVENTS[s_capacity_to_lower_level_augp] = check_capcity_to_lower_level_augp;
	EVENTS[s_capacity_to_higher_level_augp] = capacity_to_higher_level_augp;
	EVENTS[s_capacity_away_from_augment_augp] = capacity_away_from_augment_augp;
	EVENTS[s_check_capcity_to_lower_level_augp] = check_capcity_to_lower_level_augp;
	EVENTS[s_get_indexes_edges_augp] = get_indexes_edges_augp;
	EVENTS[s_current_room_sink_augp] = current_room_sink_augp;
	EVENTS[s_current_room_source_augp] = current_room_source_augp;
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

	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}
