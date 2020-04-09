
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

t_bool				init_bfs_s_to_t(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	QUE = ft_addr_lstnew((void*)SOURCE);
	TEMP_QUE = QUE;
	SOURCE->level = 0;
	return (SUCCESS);
}

t_bool				que_list_remain_bfs_s_to_t(t_project *lem_in)
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

t_bool				edge_list_remain_bfs_s_to_t(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (TEMP_LINKS)
		return (SUCCESS);
	TEMP_QUE = TEMP_QUE->next;
	return (FAIL);
}

t_bool				update_level_and_que_bfs_s_to_t(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (NEXT_ROOM != SOURCE)
	{
		NEXT_ROOM_LEVEL = CURRENT_ROOM->level + 1;
	}
	if (NEXT_ROOM != SINK)
		ft_addr_lstapp(&QUE, ft_addr_lstnew((void*)NEXT_ROOM));
	TEMP_LINKS = TEMP_LINKS->next;
	return (SUCCESS);
}

t_bool				vertex_has_level_bfs_s_to_t(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (NEXT_ROOM_LEVEL == 0)
		return (FAIL);
	TEMP_LINKS = TEMP_LINKS->next;
	return (SUCCESS);
}

t_bool				capacity_available_bfs_s_to_t(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if ((TEMP_LINK_CAPACITY == 1) || (TEMP_LINK_CAPACITY == 0 && TEMP_LINK_VISITED == 1))
	{
		lem_in->level++;
		return (SUCCESS);
	}
	TEMP_LINKS = TEMP_LINKS->next;
	return (FAIL);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_bfs_s_to_t][FAIL] = s_uninstall_machine_bfs_s_to_t;
	TRANSITIONS[s_install_machine_bfs_s_to_t][SUCCESS] = s_init_bfs_s_to_t;
	TRANSITIONS[s_init_bfs_s_to_t][SUCCESS] = s_que_list_remain_bfs_s_to_t;
	TRANSITIONS[s_que_list_remain_bfs_s_to_t][FAIL] = s_print_tables_bfs_s_to_t; // EINDE
	TRANSITIONS[s_que_list_remain_bfs_s_to_t][SUCCESS] = s_edge_list_remain_bfs_s_to_t;
	TRANSITIONS[s_edge_list_remain_bfs_s_to_t][SUCCESS] = s_capacity_available_bfs_s_to_t;
	TRANSITIONS[s_edge_list_remain_bfs_s_to_t][FAIL] = s_que_list_remain_bfs_s_to_t;
	TRANSITIONS[s_capacity_available_bfs_s_to_t][SUCCESS] = s_vertex_has_level_bfs_s_to_t;
	TRANSITIONS[s_capacity_available_bfs_s_to_t][FAIL] = s_edge_list_remain_bfs_s_to_t;
	TRANSITIONS[s_vertex_has_level_bfs_s_to_t][SUCCESS] = s_edge_list_remain_bfs_s_to_t;
	TRANSITIONS[s_vertex_has_level_bfs_s_to_t][FAIL] = s_update_level_and_que_bfs_s_to_t;
	TRANSITIONS[s_update_level_and_que_bfs_s_to_t][SUCCESS] = s_edge_list_remain_bfs_s_to_t;
	TRANSITIONS[s_print_tables_bfs_s_to_t][FAIL] = s_uninstall_machine_bfs_s_to_t;
	TRANSITIONS[s_print_tables_bfs_s_to_t][SUCCESS] = s_uninstall_machine_bfs_s_to_t;

}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_bfs_s_to_t] = NULL;
	EVENTS[s_init_bfs_s_to_t] = init_bfs_s_to_t;
	EVENTS[s_que_list_remain_bfs_s_to_t] = que_list_remain_bfs_s_to_t;
	EVENTS[s_edge_list_remain_bfs_s_to_t] = edge_list_remain_bfs_s_to_t;
	EVENTS[s_capacity_available_bfs_s_to_t] = capacity_available_bfs_s_to_t;
	EVENTS[s_vertex_has_level_bfs_s_to_t] = vertex_has_level_bfs_s_to_t;
	EVENTS[s_update_level_and_que_bfs_s_to_t] = update_level_and_que_bfs_s_to_t;
	EVENTS[s_print_tables_bfs_s_to_t] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_bfs_s_to_t);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								label_graph_s_to_t(t_project *lem_in)
{
	t_machine	*machine;

	// size_t index = 0;
	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	// while (index < ALL_ROOMS->size)
	// {
	// 	ft_printf("name %s - level %d\n", ALL_ROOMS->elem[index]->name, ((t_vertex*)(ALL_ROOMS->elem[index]->content))->level);
	// 	index++;
	// }
	
	// if (lem_in->level ==  0)
	// {
	// 	ft_printf("label = fail");
	// 	return ((FAIL));
	// }
	return (SUCCESS);
}
