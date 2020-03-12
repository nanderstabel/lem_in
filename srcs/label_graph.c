
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
	s_check_link_free_bfs_bfs,
	s_uninstall_machine_bfs,
}	e_state_bfs;

enum
{
	e_free,
	e_full,
}	e_edge;

t_bool				init_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	// lem_in->level = 1;
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
	return (FAIL);
}

t_bool				check_link_free_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (TEMP_LINKS)
	{
		if (TEMP_LINKS->address->residual == e_free )
		return (SUCCESS);
	}
	TEMP_QUE = TEMP_QUE->next;
	return (FAIL);
}

// t_bool				check_edge_free(t_project *lem_in)
// {
// 	if(FLAGS & DEBUG_O)
// 		ft_printf("\t%s\n", __func__);
// }

t_bool				check_forward_backward_bfs(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (((t_edge*)(TEMP_LINKS->address))->back == CURRENT_ROOM)
	{
		if (ROOM_FORWARD_LEVEL == 0)
		{
			ROOM_FORWARD_LEVEL++;
			ft_addr_lstapp(&TEMP_QUE, ROOM_FORWARD);
		}
	}
}		

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs][FAIL] = s_uninstall_machine_bfs;
	TRANSITIONS[s_install_machine_bfs][SUCCESS] = s_init_bfs;
	TRANSITIONS[s_init_bfs][SUCCESS] = s_que_list_remain_bfs;
	TRANSITIONS[s_que_list_remain_bfs][SUCCESS] = s_check_link_free_bfs_bfs;
	TRANSITIONS[s_que_list_remain_bfs][FAIL] = s_uninstall_machine_rms; // EINDE
	TRANSITIONS[s_check_link_free_bfs_bfs][SUCCESS] = s_get_type;
	TRANSITIONS[s_check_link_free_bfs_bfs][FAIL] = s_que_list_remain_bfs;
	// TRANSITIONS[s_get_type][SUCCESS] = s_store_room;
	// TRANSITIONS[s_store_room][FAIL] = s_uninstall_machine_rms;
	// TRANSITIONS[s_store_room][SUCCESS] = s_get_type;
	// TRANSITIONS[s_print_rooms][FAIL] = s_uninstall_machine_rms;
	// TRANSITIONS[s_print_rooms][SUCCESS] = s_uninstall_machine_rms;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_bfs] = NULL;
	EVENTS[s_init_bfs] = init_bfs;
	EVENTS[s_que_list_remain_bfs] = que_list_remain_bfs;
	// EVENTS[s_get_type] = get_type;
	// EVENTS[s_store_room] = store_room;
	// EVENTS[s_print_rooms] = print_rooms;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_rms);
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
