/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   augmenting_paths.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:00:09 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/11 18:50:52 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				init_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->level = 0;
	lem_in->round_temp =  0;
	// QUE = NULL;
	return (SUCCESS);

}
t_bool				capacity_from_source_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	CURRENT_ROOM = SINK;
	TEMP_LINKS = SINK->links;
	INDEX_COPY = CURRENT_ROOM_INDEX;
	// ft_printf("01 - CURRENT_ROOM SINK %s\n", CURRENT_ROOM->id->name);
	while (TEMP_LINKS)
	{
		// hier moet nog iets in voor het voorbeeld sink en source naast elkaar
		NEXT_ROOM_TEMP_LINKS = NEXT_ROOM_LINKS;
		while (NEXT_ROOM_TEMP_LINKS)
		{
			if (NEXT_ROOM_TEMP_LINKS_CAPACITY == 1 && NEXT_ROOM_INDEX_CMP == INDEX_COPY)
			{
				if (TEMP_LINK_CAPACITY == 1 && NEXT_ROOM_LEVEL != 0)
				{
					lem_in->level++;
					TEMP_LINK_CAPACITY = 0;
					// ft_printf("02 - room: %s visited %d - next room: %s visited %d functie %s\n", CURRENT_ROOM->id->name, CURRENT_ROOM->visited, NEXT_ROOM->id->name, NEXT_ROOM->visited, __func__);
					CURRENT_ROOM = NEXT_ROOM;
					return (SUCCESS);
				}
			}
			NEXT_ROOM_TEMP_LINKS = NEXT_ROOM_TEMP_LINKS->next;
		}
		TEMP_LINKS = TEMP_LINKS->next;
	}
	return (FAIL);
}

// moet nog inbouwen dat hij het doet bij een map waar sink en source meteen verbonden zijn
// en er nog 1 doodlopend pat is vanuit source-
t_bool 				capacity_to_lower_level_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	INDEX_COPY = CURRENT_ROOM_INDEX;
	// ft_printf("03 - room: %s visited %d - next room: %s visited %d functie %s\n", CURRENT_ROOM->id->name, CURRENT_ROOM->visited, NEXT_ROOM->id->name, NEXT_ROOM->visited, __func__);
	while (TEMP_LINKS)
	{
		// ft_printf("04 - next room: %s visited %d functie %s\n", NEXT_ROOM->id->name, NEXT_ROOM->visited, __func__);
		if (CURRENT_ROOM->visited == 1)
			break;
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
			// ft_printf("05  - room: %s visited %d - next room: %s visited %d functie %s\n", CURRENT_ROOM->id->name, CURRENT_ROOM->visited, NEXT_ROOM->id->name, NEXT_ROOM->visited, __func__);
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
		ft_printf("\t%s\n", __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	while (TEMP_LINKS)
	{
		// ft_printf("07 -next room: %s visited %d  link visited %d capacity %d\n", NEXT_ROOM->id->name, NEXT_ROOM->visited, TEMP_LINK_VISITED, TEMP_LINK_CAPACITY);
		if ((TEMP_LINK_CAPACITY == 0 && NEXT_ROOM_LEVEL == CURRENT_ROOM->level + 1 && NEXT_ROOM->visited == 1) || (TEMP_LINK_CAPACITY == 0 && NEXT_ROOM_LEVEL == CURRENT_ROOM->level + 1 && NEXT_ROOM == SINK))
		{
				// ft_printf("06 - room: %s visited %d - next room: %s visited %d functie %s\n", CURRENT_ROOM->id->name, CURRENT_ROOM->visited, NEXT_ROOM->id->name, NEXT_ROOM->visited, __func__);
				CURRENT_LINK = ((t_edge*)(TEMP_LINKS->address));
				ROUND_NR++;
				lem_in->round_temp++;
				return (SUCCESS);
		}
		TEMP_LINKS = TEMP_LINKS->next;
	}
	// ft_printf("room name %s\n", CURRENT_ROOM->id->name);
	return (FAIL);
}

t_bool				get_indexes_edges_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!AUGMENT_PATHS)
	{
		AUGMENT_PATHS = ft_addr_lstnew((void*)EDGE_INDEX);
	}
	else
		ft_addr_lstapp(&AUGMENT_PATHS, ft_addr_lstnew((void*)EDGE_INDEX));
	INDEX_COPY = CURRENT_ROOM_INDEX;
	CURRENT_LINK_CAPACITY = 0;
	CURRENT_ROOM = CURRENT_LINK->next;
	// ft_printf("room: %s - functie %s\n", CURRENT_ROOM->id->name,  __func__);
	TEMP_LINKS = CURRENT_ROOM->links;
	while (NEXT_ROOM_INDEX != INDEX_COPY)
	{
		TEMP_LINKS = TEMP_LINKS->next;
	}
	CURRENT_LINK = ((t_edge*)(TEMP_LINKS->address));
	ft_addr_lstapp(&AUGMENT_PATHS, ft_addr_lstnew((void*)EDGE_INDEX));
	return (SUCCESS);
}

t_bool				current_room_sink_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (CURRENT_ROOM == SINK)
	{
		ft_printf("sink reached\n");
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				current_room_source_augp(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (CURRENT_ROOM == SOURCE)
	{
		ft_printf("source reached\n");
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				clear_capacity_on_graph_augp(t_project *lem_in)
{
	size_t 	index;
	t_adlist *temp;
	temp = AUGMENT_PATHS;

	index = 0;
	// int num = 0;
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->level)
	{
		while (index < ALL_LINKS->size)
		{
			if (((t_edge*)(ALL_LINKS->elem[index]->content))->visited == 1 && !lem_in->round_temp)
			{
				// num++;
				((t_edge*)(ALL_LINKS->elem[index]->content))->capacity = 0;
			}
			else
			{
				((t_edge*)(ALL_LINKS->elem[index]->content))->capacity = 1;
				((t_edge*)(ALL_LINKS->elem[index]->content))->visited = 0;
			}
			index++;
		}
		while (temp)
		{
			// ft_printf("test1\n");
			((t_edge*)(ALL_LINKS->elem[((long long)(temp->address))]->content))->capacity = 0;
			// ((t_edge*)(ALL_LINKS->elem[((long long)(temp->address))]->content))->visited = 1;

			temp = temp->next;
		}
	}
	index = 0;
	if (lem_in->level)
	{
		while (index < ALL_ROOMS->size)
		{
			((t_vertex*)(ALL_ROOMS->elem[index]->content))->level = 0;
			// ft_printf("test1\n");
			if (lem_in->round_temp)
			{
				// ft_printf("test2\n");
				((t_vertex*)(ALL_ROOMS->elem[index]->content))->visited = 0;
			}
			index++;
		}
		
	}
	index = 0;
	// temp = AUGMENT_PATHS;
	// while (temp)
	// {
	// 	ft_printf("index %d\n", ((long long)(temp->address)));
	// 	temp = temp->next;
	// }
	// ft_printf("num of links %d\n", num);
	// while (index < ALL_LINKS->size)
	// {
	// 	ft_printf("index %d - capacity %d\n", index, ((t_edge*)(ALL_LINKS->elem[index]->content))->capacity);
	// 	index++;
	// }
	// while (index < ALL_ROOMS->size)
	// {
	// 	ft_printf("level %d\n", ((t_vertex*)(ALL_ROOMS->elem[index]->content))->level);
	// 	index++;
	// }
	// ft_addr_lstdel(&QUE);
	// exit(1);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_install_machine_bfs][SUCCESS] = s_init_augp;
	TRANSITIONS[s_init_augp][SUCCESS] = s_capacity_from_source_augp;
	TRANSITIONS[s_capacity_from_source_augp][SUCCESS] = s_capacity_to_lower_level_augp;
	TRANSITIONS[s_capacity_from_source_augp][FAIL] = s_clear_capacity_on_graph_augp; // EINDE
	TRANSITIONS[s_capacity_to_lower_level_augp][SUCCESS] = s_current_room_sink_augp;
	TRANSITIONS[s_capacity_to_lower_level_augp][FAIL] = s_capacity_to_higher_level_augp;
	TRANSITIONS[s_current_room_sink_augp][SUCCESS] = s_capacity_from_source_augp;
	TRANSITIONS[s_current_room_sink_augp][FAIL] = s_capacity_to_lower_level_augp;
	// TRANSITIONS[s_capacity_to_higher_level_augp][FAIL] = s_capacity_away_from_augment_augp; // <<< volgens mij kan er geen fail zijn
	TRANSITIONS[s_capacity_to_higher_level_augp][SUCCESS] = s_get_indexes_edges_augp;
	TRANSITIONS[s_get_indexes_edges_augp][SUCCESS] = s_clear_capacity_on_graph_augp;
	TRANSITIONS[s_current_room_source_augp][FAIL] = s_check_capacity_to_lower_level_augp;
	TRANSITIONS[s_current_room_source_augp][SUCCESS] = s_capacity_from_source_augp;
	TRANSITIONS[s_check_capacity_to_lower_level_augp][FAIL] = s_capacity_away_from_augment_augp;
	TRANSITIONS[s_check_capacity_to_lower_level_augp][SUCCESS] = s_capacity_to_lower_level_augp;
	TRANSITIONS[s_capacity_away_from_augment_augp][FAIL] = s_capacity_to_higher_level_augp;
	TRANSITIONS[s_capacity_away_from_augment_augp][SUCCESS] = s_check_capacity_to_lower_level_augp;
	TRANSITIONS[s_clear_capacity_on_graph_augp][SUCCESS] = s_print_tables_augp;
	TRANSITIONS[s_print_tables_augp][FAIL] = s_uninstall_machine_augp;
	TRANSITIONS[s_print_tables_augp][SUCCESS] = s_uninstall_machine_augp;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_augp] = NULL;
	EVENTS[s_init_augp] = init_augp;
	EVENTS[s_capacity_from_source_augp] = capacity_from_source_augp;
	EVENTS[s_capacity_to_lower_level_augp] = capacity_to_lower_level_augp;
	EVENTS[s_capacity_to_higher_level_augp] = capacity_to_higher_level_augp;
	// EVENTS[s_capacity_away_from_augment_augp] = capacity_away_from_augment_augp;
	// EVENTS[s_check_capacity_to_lower_level_augp] = check_capacity_to_lower_level_augp;
	EVENTS[s_get_indexes_edges_augp] = get_indexes_edges_augp;
	EVENTS[s_current_room_sink_augp] = current_room_sink_augp;
	EVENTS[s_current_room_source_augp] = current_room_source_augp;
	EVENTS[s_clear_capacity_on_graph_augp] = clear_capacity_on_graph_augp;
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
	ft_printf("round: %d\n", ROUND_NR);	
	
	// size_t index = 0;

	// while (index < ALL_ROOMS->size)
	// {
	// 	((t_vertex*)(ALL_ROOMS->elem[index]->content))->visited = 0;
	// 	index++;
	// }




	if (lem_in->round_temp == 0)
	{
		return (FAIL);
	}
	return (SUCCESS);
}
