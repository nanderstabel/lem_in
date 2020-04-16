/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:57:21 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 10:30:41 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->index = 0;
	lem_in->source->level = __INT_MAX__;
	while (lem_in->index < lem_in->all_rooms->size)
	{
		lem_in->current_room = lem_in->all_rooms->elem[lem_in->index]->content;
		ft_addr_lstsrt(&lem_in->current_room->links, sort_by_level);
		lem_in->current_room->selected = lem_in->current_room->links;
		++lem_in->index;
	}
	return (SUCCESS);
}

t_bool				start_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->current_room = lem_in->source;
	lem_in->current_path = ft_addr_lstnew((void *)lem_in->current_room);
	lem_in->index = 0;
	if (!lem_in->current_room || !lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tStart path\n");
	return (SUCCESS);
}

t_bool				find_next_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (lem_in->current_room->selected)
	{
		lem_in->temp = lem_in->current_room->selected;
		if (TEMP_LINK_CAPACITY && NEXT_ROOM_LEVEL < lem_in->current_room->level)
			if (!NEXT_ROOM->visited)
				return (SUCCESS);
		lem_in->current_room->selected = lem_in->current_room->selected->next;
	}
	return (FAIL);
}

t_bool				backtrack_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->current_room == lem_in->source)
		return (FAIL);
	lem_in->current_room->visited = 0;
	lem_in->current_room = (t_vertex *)lem_in->current_path->next->address;
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tBacktracked to: %s\n", lem_in->current_room->id->name);
	return (SUCCESS);
}

t_bool				delete_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	ft_addr_lstdel(&lem_in->current_path);
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tDeleted path\n");
	return (FAIL);
}

t_bool				remove_room(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->current_room || !lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	lem_in->temp = lem_in->current_room->selected;
	TEMP_LINK_CAPACITY = 1;
	TEMP_LINK_VISITED = 0;
	lem_in->que_list = lem_in->current_path;
	lem_in->current_path = lem_in->current_path->next;
	ft_addr_lstdelone(&lem_in->que_list);
	--lem_in->index;
	lem_in->current_room->selected = lem_in->current_room->selected->next;
	return (SUCCESS);
}

t_bool				traverse_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tTravelled from %s, to ", lem_in->current_room->id->name);
	if (!NEXT_ROOM || !lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	lem_in->current_room = NEXT_ROOM;
	if (lem_in->flags & DFS_O)
		ft_printf("%s\n", lem_in->current_room->id->name);
	TEMP_LINK_CAPACITY = 0;
	TEMP_LINK_VISITED = 1;
	ft_addr_lstadd(&lem_in->current_path, \
		ft_addr_lstnew((void *)lem_in->current_room));
	++lem_in->index;
	return (SUCCESS);
}

t_bool				check_sink(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->current_room != lem_in->sink)
	{
		lem_in->current_room->visited = 1;
		return (FAIL);
	}
	if (lem_in->flags & DFS_O)
		ft_printf("\t\tFound sink\n");
	return (SUCCESS);
}

t_bool				store_path(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (!lem_in->current_path)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	lem_in->current_path = ft_addr_lstrev(lem_in->current_path);
	ft_addr_lstadd(&lem_in->current_path, \
		ft_addr_lstnew((void *)lem_in->index));
	ft_addr_lstadd(&lem_in->current_path, \
		ft_addr_lstnew((void *)lem_in->round_nr));
	if (lem_in->all_paths)
		ft_addr_lstadd(&lem_in->all_paths, \
			ft_addr_lstnew(lem_in->current_path));
	else
		lem_in->all_paths = ft_addr_lstnew(lem_in->current_path);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	t_state		**transitions;

	transitions = (*mconfig)->transitions;
	transitions[s_install_machine_dfs][FAIL] = s_uninstall_machine_dfs;
	transitions[s_install_machine_dfs][SUCCESS] = s_sort_links_lists;
	transitions[s_sort_links_lists][FAIL] = s_uninstall_machine_dfs;
	transitions[s_sort_links_lists][SUCCESS] = s_start_path;
	transitions[s_start_path][FAIL] = s_uninstall_machine_dfs;
	transitions[s_start_path][SUCCESS] = s_find_next_room;
	transitions[s_find_next_room][FAIL] = s_backtrack_path;
	transitions[s_find_next_room][SUCCESS] = s_traverse_path;
	transitions[s_backtrack_path][FAIL] = s_delete_path;
	transitions[s_backtrack_path][SUCCESS] = s_remove_room;
	transitions[s_delete_path][FAIL] = s_uninstall_machine_dfs;
	transitions[s_delete_path][SUCCESS] = s_print_tables_dfs;
	transitions[s_remove_room][FAIL] = s_uninstall_machine_dfs;
	transitions[s_remove_room][SUCCESS] = s_find_next_room;
	transitions[s_traverse_path][FAIL] = s_uninstall_machine_dfs;
	transitions[s_traverse_path][SUCCESS] = s_check_sink;
	transitions[s_check_sink][FAIL] = s_find_next_room;
	transitions[s_check_sink][SUCCESS] = s_store_path;
	transitions[s_store_path][FAIL] = s_uninstall_machine_dfs;
	transitions[s_store_path][SUCCESS] = s_print_tables_dfs;
	transitions[s_print_tables_dfs][FAIL] = s_uninstall_machine_dfs;
	transitions[s_print_tables_dfs][SUCCESS] = s_uninstall_machine_dfs;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_dfs] = NULL;
	(*mconfig)->events[s_sort_links_lists] = sort_links_lists;
	(*mconfig)->events[s_start_path] = start_path;
	(*mconfig)->events[s_find_next_room] = find_next_room;
	(*mconfig)->events[s_backtrack_path] = backtrack_path;
	(*mconfig)->events[s_delete_path] = delete_path;
	(*mconfig)->events[s_remove_room] = remove_room;
	(*mconfig)->events[s_traverse_path] = traverse_path;
	(*mconfig)->events[s_check_sink] = check_sink;
	(*mconfig)->events[s_store_path] = store_path;
	(*mconfig)->events[s_print_tables_dfs] = print_tables;
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

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	lem_in->count++;
	if (!lem_in->index)
		return (FAIL);
	if (lem_in->error)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
