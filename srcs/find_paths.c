/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:57:21 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/16 15:25:34 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

enum
{
	s_install_machine_dfs,
	s_sort_links_lists,
	s_set_to_source,
	s_find_next_room,
	s_backtrack_path,
	s_traverse_path,
	s_check_sink,
	s_store_path,
	s_uninstall_machine_dfs,
}	e_state_dfs;

int					sort_by_level(void *a, void *b)
{
	t_vertex	*room_a;
	t_vertex	*room_b;

	room_a = ((t_edge *)(((t_adlist *)a)->address))->next;
	room_b = ((t_edge *)(((t_adlist *)b)->address))->next;
	if (room_a->level < room_b->level)
		return (1);
	return (0);
}

t_bool				sort_links_lists(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	INDEX = 0;
	while (INDEX < ALL_ROOMS->size)
	{
		CURRENT_ROOM = ALL_ROOMS->elem[INDEX]->content;
		ft_addr_lstsrt(&CURRENT_ROOM->links, sort_by_level);
	}
	return (SUCCESS);
}

t_bool				set_to_source(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				find_next_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				backtrack_paths(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				traverse_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				check_sink(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				store_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_uninstall_machine_dfs;
	
	TRANSITIONS[s_sort_links_lists][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_sort_links_lists][SUCCESS] = s_uninstall_machine_dfs;
	
	TRANSITIONS[s_set_to_source][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_set_to_source][SUCCESS] = s_uninstall_machine_dfs;
	
	TRANSITIONS[s_find_next_room][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_find_next_room][SUCCESS] = s_uninstall_machine_dfs;
	
	TRANSITIONS[s_backtrack_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_backtrack_path][SUCCESS] = s_uninstall_machine_dfs;
	
	TRANSITIONS[s_traverse_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_traverse_path][SUCCESS] = s_uninstall_machine_dfs;
	
	TRANSITIONS[s_check_sink][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_check_sink][SUCCESS] = s_uninstall_machine_dfs;
	
	TRANSITIONS[s_store_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_store_path][SUCCESS] = s_uninstall_machine_dfs;
	
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_dfs] = NULL;
	EVENTS[s_sort_links_lists] = sort_links_lists;
	EVENTS[s_set_to_source] = set_to_source;
	EVENTS[s_find_next_room] = find_next_room;
	EVENTS[s_backtrack_path] = backtrack_paths;
	EVENTS[s_traverse_path] = traverse_path;
	EVENTS[s_check_sink] = check_sink;
	EVENTS[s_store_path] = store_path;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_rms);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								find_paths(t_project *lem_in)
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
