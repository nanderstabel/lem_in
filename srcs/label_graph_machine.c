/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_graph.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:49 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 14:02:38 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_install_machine_bfs][SUCCESS] = s_init_bfs;
	TRANSITIONS[s_init_bfs][SUCCESS] = s_que_list_remain_bfs;
	TRANSITIONS[s_que_list_remain_bfs][FAIL] = s_print_tables_bfs;
	TRANSITIONS[s_que_list_remain_bfs][SUCCESS] = s_edge_list_remain_bfs;
	TRANSITIONS[s_edge_list_remain_bfs][SUCCESS] = s_capacity_available_bfs;
	TRANSITIONS[s_edge_list_remain_bfs][FAIL] = s_que_list_remain_bfs;
	TRANSITIONS[s_capacity_available_bfs][SUCCESS] = s_vertex_has_level_bfs;
	TRANSITIONS[s_capacity_available_bfs][FAIL] = s_edge_list_remain_bfs;
	TRANSITIONS[s_vertex_has_level_bfs][SUCCESS] = s_edge_list_remain_bfs;
	TRANSITIONS[s_vertex_has_level_bfs][FAIL] = s_update_level_and_que_bfs;
	TRANSITIONS[s_update_level_and_que_bfs][SUCCESS] = s_edge_list_remain_bfs;
	TRANSITIONS[s_print_tables_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_print_tables_bfs][SUCCESS] = s_uninstall_machine_bfs;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_bfs] = NULL;
	EVENTS[s_init_bfs] = init_bfs;
	EVENTS[s_que_list_remain_bfs] = que_list_remain_bfs;
	EVENTS[s_edge_list_remain_bfs] = edge_list_remain_bfs;
	EVENTS[s_capacity_available_bfs] = capacity_available_bfs;
	EVENTS[s_vertex_has_level_bfs] = vertex_has_level_bfs;
	EVENTS[s_update_level_and_que_bfs] = update_level_and_que_bfs;
	EVENTS[s_print_tables_bfs] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_bfs);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				label_graph(t_project *lem_in)
{
	t_machine	*machine;

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	return (SUCCESS);
}