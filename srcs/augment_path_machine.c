/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   augment_path_machine.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:00:09 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/17 11:30:30 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_install_machine_bfs][SUCCESS] = s_init_augp;
	TRANSITIONS[s_init_augp][SUCCESS] = s_capacity_from_sink_augp;
	TRANSITIONS[s_capacity_from_sink_augp][SUCCESS] = s_move_lower_level_augp;
	TRANSITIONS[s_capacity_from_sink_augp][FAIL] = s_clear_rooms_on_graph_augp;
	TRANSITIONS[s_move_lower_level_augp][SUCCESS] = s_current_room_sink_augp;
	TRANSITIONS[s_move_lower_level_augp][FAIL] = s_check_augment_path_augp;
	TRANSITIONS[s_current_room_sink_augp][SUCCESS] = s_capacity_from_sink_augp;
	TRANSITIONS[s_current_room_sink_augp][FAIL] = s_move_lower_level_augp;
	TRANSITIONS[s_check_augment_path_augp][FAIL] = s_clear_rooms_on_graph_augp;
	TRANSITIONS[s_check_augment_path_augp][SUCCESS] = s_get_indexes_edges_augp;
	TRANSITIONS[s_get_indexes_edges_augp][SUCCESS] =
	s_clear_rooms_on_graph_augp;
	TRANSITIONS[s_clear_rooms_on_graph_augp][SUCCESS] =
	s_clear_links_on_graph_augp;
	TRANSITIONS[s_clear_links_on_graph_augp][SUCCESS] = s_print_tables_augp;
	TRANSITIONS[s_print_tables_augp][FAIL] = s_uninstall_machine_augp;
	TRANSITIONS[s_print_tables_augp][SUCCESS] = s_uninstall_machine_augp;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_augp] = NULL;
	EVENTS[s_init_augp] = init_augp;
	EVENTS[s_capacity_from_sink_augp] = capacity_from_sink_augp;
	EVENTS[s_move_lower_level_augp] = move_lower_level_augp;
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

t_bool				augmenting_paths(t_project *lem_in)
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
