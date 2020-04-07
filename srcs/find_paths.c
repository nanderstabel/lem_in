/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:57:21 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/07 14:37:46 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

enum
{
	s_install_machine_dfs,
	s_sort_links_lists,
	s_start_path,
	s_find_next_room,
	s_backtrack_path,
	s_remove_room,
	s_delete_path,
	s_traverse_path,
	s_check_sink,
	s_store_path,
	s_print_tables_dfs,
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
		SELECTED = CURRENT_ROOM->links;
		++INDEX;
	}
	return (SUCCESS);
}

t_bool				start_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	CURRENT_ROOM = SOURCE;
	CURRENT_PATH = ft_addr_lstnew((void *)CURRENT_ROOM);
	INDEX = 0;
	if (!CURRENT_ROOM || !CURRENT_PATH)
		return (ERROR_LOG(FAIL));
	return (SUCCESS);
}

t_bool				find_next_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (SELECTED)
	{
		TEMP_LINKS = SELECTED;
		if (TEMP_LINK_CAPACITY && NEXT_ROOM_LEVEL < CURRENT_ROOM->level)
			if (!NEXT_ROOM->visited)
				return (SUCCESS);
		SELECTED = SELECTED->next;
	}
	return (FAIL);
}

t_bool				backtrack_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (CURRENT_ROOM == SOURCE)
		return (FAIL);
	CURRENT_ROOM->visited = 0;
	CURRENT_ROOM = (t_vertex *)CURRENT_PATH->next->address;
	if (FLAGS & DFS_O)
		ft_printf("\t\tBacktracked to: %s\n", CURRENT_ROOM->id->name);
	return (SUCCESS);
}

t_bool				delete_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!CURRENT_PATH)
		return (ERROR_LOG(FAIL));
	ft_addr_lstdel(&CURRENT_PATH);
	return (SUCCESS);
}

t_bool				remove_room(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!CURRENT_ROOM || !CURRENT_PATH)
		return (ERROR_LOG(FAIL));
	TEMP_LINKS = SELECTED;
	TEMP_LINK_CAPACITY = 1;
	QUE = CURRENT_PATH;
	CURRENT_PATH = CURRENT_PATH->next;
	ft_addr_lstdelone(&QUE);
	--INDEX;
	SELECTED = SELECTED->next;
	return (SUCCESS);
}

t_bool				traverse_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (FLAGS & DFS_O)
		ft_printf("\t\tTravelled from %s, to ", CURRENT_ROOM->id->name);
	if (!NEXT_ROOM)
		return(ERROR_LOG(FAIL) || !CURRENT_PATH);
	CURRENT_ROOM = NEXT_ROOM;
	if (FLAGS & DFS_O)
		ft_printf("%s\n", CURRENT_ROOM->id->name);
	TEMP_LINK_CAPACITY = 0;
	ft_addr_lstadd(&CURRENT_PATH, ft_addr_lstnew((void *)CURRENT_ROOM));
	++INDEX;
	return (SUCCESS);
}

t_bool				check_sink(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (CURRENT_ROOM != SINK)
	{
		CURRENT_ROOM->visited = 1;
		return (FAIL);
	}
	return (SUCCESS);
}

t_bool				store_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!CURRENT_PATH)
		return (ERROR_LOG(FAIL));
	CURRENT_PATH = ft_addr_lstrev(CURRENT_PATH);
	ft_addr_lstadd(&CURRENT_PATH, ft_addr_lstnew((void *)INDEX));
	ft_addr_lstadd(&CURRENT_PATH, ft_addr_lstnew((void *)ROUND_NR));
	if (ALL_PATHS)
		ft_addr_lstadd(&ALL_PATHS, ft_addr_lstnew(CURRENT_PATH));
	else
		ALL_PATHS = ft_addr_lstnew(CURRENT_PATH);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_sort_links_lists;
	TRANSITIONS[s_sort_links_lists][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_sort_links_lists][SUCCESS] = s_start_path;
	TRANSITIONS[s_start_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_start_path][SUCCESS] = s_find_next_room;
	TRANSITIONS[s_find_next_room][FAIL] = s_backtrack_path;
	TRANSITIONS[s_find_next_room][SUCCESS] = s_traverse_path;
	TRANSITIONS[s_backtrack_path][FAIL] = s_delete_path;
	TRANSITIONS[s_backtrack_path][SUCCESS] = s_remove_room;
	TRANSITIONS[s_delete_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_delete_path][SUCCESS] = s_print_tables_dfs;
	TRANSITIONS[s_remove_room][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_remove_room][SUCCESS] = s_find_next_room;
	TRANSITIONS[s_traverse_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_traverse_path][SUCCESS] = s_check_sink;
	TRANSITIONS[s_check_sink][FAIL] = s_find_next_room;
	TRANSITIONS[s_check_sink][SUCCESS] = s_store_path;
	TRANSITIONS[s_store_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_store_path][SUCCESS] = s_start_path;
	TRANSITIONS[s_print_tables_dfs][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_print_tables_dfs][SUCCESS] = s_uninstall_machine_dfs;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_dfs] = NULL;
	EVENTS[s_sort_links_lists] = sort_links_lists;
	EVENTS[s_start_path] = start_path;
	EVENTS[s_find_next_room] = find_next_room;
	EVENTS[s_backtrack_path] = backtrack_path;
	EVENTS[s_delete_path] = delete_path;
	EVENTS[s_remove_room] = remove_room;
	EVENTS[s_traverse_path] = traverse_path;
	EVENTS[s_check_sink] = check_sink;
	EVENTS[s_store_path] = store_path;
	EVENTS[s_print_tables_dfs] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_dfs);
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
