/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:57:21 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/11 15:29:50 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

enum
{
	s_install_machine_dfs,
	s_start_path,
	s_find_shortest_link,
	s_delete_path,
	s_travel_forward,
	s_add_to_path,
	s_check_sink,
	s_store_path,
	s_uninstall_machine_dfs,
}	e_state_dfs;

t_bool				start_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				find_shortest_link(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				delete_path(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				travel_forward(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

t_bool				add_to_path(t_project *lem_in)
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
	TRANSITIONS[s_start_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_start_path][SUCCESS] = s_uninstall_machine_dfs;
	TRANSITIONS[s_find_shortest_link][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_find_shortest_link][SUCCESS] = s_uninstall_machine_dfs;
	TRANSITIONS[s_delete_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_delete_path][SUCCESS] = s_uninstall_machine_dfs;
	TRANSITIONS[s_travel_forward][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_travel_forward][SUCCESS] = s_uninstall_machine_dfs;
	TRANSITIONS[s_add_to_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_add_to_path][SUCCESS] = s_uninstall_machine_dfs;
	TRANSITIONS[s_check_sink][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_check_sink][SUCCESS] = s_uninstall_machine_dfs;
	TRANSITIONS[s_store_path][FAIL] = s_uninstall_machine_dfs;
	TRANSITIONS[s_store_path][SUCCESS] = s_uninstall_machine_dfs;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_dfs] = NULL;
	EVENTS[s_start_path] = start_path;
	EVENTS[s_find_shortest_link] = find_shortest_link;
	EVENTS[s_delete_path] = delete_path;
	EVENTS[s_travel_forward] = travel_forward;
	EVENTS[s_add_to_path] = add_to_path;
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
