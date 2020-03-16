
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_graph.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:49 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/10 18:09:09 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
enum
{
	s_install_machine_bfs,
	s_init_bfs,
	s_que_list_remain_bfs,
	s_edge_list_remain_bfs,
	s_vertex_has_level_bfs,
	s_capacity_available_bfs,
	s_update_level_and_que_bfs,
	s_uninstall_machine_bfs,
}	e_state_bfs;

t_bool				init_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	QUE = ft_addr_lstnew((void*)SOURCE);
	TEMP_QUE = QUE;
	return (SUCCESS);
}

t_bool				que_list_remain_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (TEMP_QUE)
	{
		CURRENT_ROOM = VERTEX_IN_LIST;
		TEMP_LINKS = CURRENT_ROOM_LINKS;
		return (SUCCESS);
	}
	ft_addr_lstdel(&QUE);
	return (FAIL);
}

t_bool				edge_list_remain_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (TEMP_LINKS)
		return (SUCCESS);
	TEMP_QUE = TEMP_QUE->next;
	return (FAIL);
}

t_bool				update_level_and_que_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (TEMP_LINKS)
		NEXT_ROOM_LEVEL = CURRENT_ROOM->level + 1;
	if (NEXT_ROOM != SINK)
		ft_addr_lstapp(&QUE, ft_addr_lstnew((void*)NEXT_ROOM));
	TEMP_LINKS = TEMP_LINKS->next;
	return (SUCCESS);
}

t_bool				vertex_has_level_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (NEXT_ROOM_LEVEL == 0)
		return (FAIL);
	TEMP_LINKS = TEMP_LINKS->next;
	return (SUCCESS);
}

t_bool				capacity_available_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (TEMP_LINK_CAPACITY == 1)
		return (SUCCESS);
	TEMP_LINKS = TEMP_LINKS->next;
	return (FAIL);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_install_machine_bfs][SUCCESS] = s_init_bfs;
	TRANSITIONS[s_init_bfs][SUCCESS] = s_que_list_remain_bfs;
	TRANSITIONS[s_que_list_remain_bfs][FAIL] = s_uninstall_machine_rms; // EINDE
	TRANSITIONS[s_que_list_remain_bfs][SUCCESS] = s_edge_list_remain_bfs;
	TRANSITIONS[s_edge_list_remain_bfs][SUCCESS] = s_capacity_available_bfs;
	TRANSITIONS[s_edge_list_remain_bfs][FAIL] = s_que_list_remain_bfs;
	TRANSITIONS[s_capacity_available_bfs][SUCCESS] = s_vertex_has_level_bfs;
	TRANSITIONS[s_capacity_available_bfs][FAIL] = s_edge_list_remain_bfs;
	TRANSITIONS[s_vertex_has_level_bfs][SUCCESS] = s_edge_list_remain_bfs;
	TRANSITIONS[s_vertex_has_level_bfs][FAIL] = s_update_level_and_que_bfs;
	TRANSITIONS[s_update_level_and_que_bfs][SUCCESS] = s_edge_list_remain_bfs;
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
	// EVENTS[s_print_rooms] = print_rooms;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_bfs);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								label_graph(t_project *lem_in)
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
