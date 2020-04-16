/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_graph_st_machine.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:49 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 14:20:43 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs_st][FAIL] = s_uninstall_machine_bfs_st;
	TRANSITIONS[s_install_machine_bfs_st][SUCCESS] = s_init_bfs_st;
	TRANSITIONS[s_init_bfs_st][SUCCESS] = s_que_list_remain_bfs_st;
	TRANSITIONS[s_que_list_remain_bfs_st][FAIL] = s_print_tables_bfs_st;
	TRANSITIONS[s_que_list_remain_bfs_st][SUCCESS] = s_edge_list_remain_bfs_st;
	TRANSITIONS[s_edge_list_remain_bfs_st][SUCCESS] =
	s_capacity_available_bfs_st;
	TRANSITIONS[s_edge_list_remain_bfs_st][FAIL] = s_que_list_remain_bfs_st;
	TRANSITIONS[s_capacity_available_bfs_st][SUCCESS] =
	s_vertex_has_level_bfs_st;
	TRANSITIONS[s_capacity_available_bfs_st][FAIL] = s_edge_list_remain_bfs_st;
	TRANSITIONS[s_vertex_has_level_bfs_st][SUCCESS] = s_edge_list_remain_bfs_st;
	TRANSITIONS[s_vertex_has_level_bfs_st][FAIL] =
	s_update_level_and_que_bfs_st;
	TRANSITIONS[s_update_level_and_que_bfs_st][SUCCESS] =
	s_edge_list_remain_bfs_st;
	TRANSITIONS[s_print_tables_bfs_st][FAIL] = s_uninstall_machine_bfs_st;
	TRANSITIONS[s_print_tables_bfs_st][SUCCESS] = s_uninstall_machine_bfs_st;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_bfs_st] = NULL;
	EVENTS[s_init_bfs_st] = init_bfs_st;
	EVENTS[s_que_list_remain_bfs_st] = que_list_remain_bfs_st;
	EVENTS[s_edge_list_remain_bfs_st] = edge_list_remain_bfs_st;
	EVENTS[s_capacity_available_bfs_st] = capacity_available_bfs_st;
	EVENTS[s_vertex_has_level_bfs_st] = vertex_has_level_bfs_st;
	EVENTS[s_update_level_and_que_bfs_st] = update_level_and_que_bfs_st;
	EVENTS[s_print_tables_bfs_st] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_bfs_st);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				label_graph_s_to_t(t_project *lem_in)
{
	t_machine	*machine;

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
	{
		run_machine(machine, lem_in);
	}
	uninstall_machine(&machine);
	return (SUCCESS);
}
