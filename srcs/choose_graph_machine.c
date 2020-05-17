/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_graph_machine.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/04 13:57:07 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/18 01:34:32 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	t_state		**transitions;

	transitions = (*mconfig)->transitions;
	transitions[s_install_machine_rms][FAIL] = s_uninstall_machine_cg;
	transitions[s_install_machine_rms][SUCCESS] = s_set_global_vars;
	transitions[s_set_global_vars][FAIL] = s_uninstall_machine_cg;
	transitions[s_set_global_vars][SUCCESS] = s_set_graph_vars;
	transitions[s_set_graph_vars][FAIL] = s_uninstall_machine_cg;
	transitions[s_set_graph_vars][SUCCESS] = s_get_graph;
	transitions[s_get_graph][FAIL] = s_delete_excess_paths;
	transitions[s_get_graph][SUCCESS] = s_finish_graph_calculation;
	transitions[s_delete_excess_paths][FAIL] = s_uninstall_machine_cg;
	transitions[s_delete_excess_paths][SUCCESS] = s_clean_pathslist;
	transitions[s_clean_pathslist][FAIL] = s_uninstall_machine_cg;
	transitions[s_clean_pathslist][SUCCESS] = s_print_tables_cg;
	transitions[s_finish_graph_calculation][FAIL] = s_calculate_turn;
	transitions[s_finish_graph_calculation][SUCCESS] = s_update_stored_graph;
	transitions[s_calculate_turn][FAIL] = s_uninstall_machine_cg;
	transitions[s_calculate_turn][SUCCESS] = s_finish_graph_calculation;
	transitions[s_update_stored_graph][FAIL] = s_uninstall_machine_cg;
	transitions[s_update_stored_graph][SUCCESS] = s_set_graph_vars;
	transitions[s_print_tables_cg][FAIL] = s_uninstall_machine_cg;
	transitions[s_print_tables_cg][SUCCESS] = s_uninstall_machine_cg;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_cg] = NULL;
	(*mconfig)->events[s_set_global_vars] = set_global_vars;
	(*mconfig)->events[s_set_graph_vars] = set_graph_vars;
	(*mconfig)->events[s_get_graph] = get_graph;
	(*mconfig)->events[s_delete_excess_paths] = delete_excess_paths;
	(*mconfig)->events[s_clean_pathslist] = clean_pathslist;
	(*mconfig)->events[s_finish_graph_calculation] = finish_graph_calculation;
	(*mconfig)->events[s_calculate_turn] = calculate_turn;
	(*mconfig)->events[s_update_stored_graph] = update_stored_graph;
	(*mconfig)->events[s_print_tables_cg] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_cg);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				choose_graph(t_project *lem_in)
{
	t_machine	*machine;

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (lem_in->error)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
