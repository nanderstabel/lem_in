/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:57:21 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:30:14 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

t_bool				find_paths(t_project *lem_in)
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
