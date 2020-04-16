/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_graph.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/04 13:57:07 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/15 09:17:48 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

enum
{
	s_install_machine_cg,
	s_set_global_vars,
	s_set_graph_vars,
	s_get_graph,
	s_delete_excess_paths,
	s_clean_pathslist,
	s_finish_graph_calculation,
	s_calculate_turn,
	s_update_stored_graph,
	s_print_tables_cg,
	s_uninstall_machine_cg,
}	e_state_cg;

t_bool				set_global_vars(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	INDEX = 0;
	TEMP_QUE = ALL_PATHS;
	lem_in->nturns = __INT_MAX__;
	INDEX = 0;
	return (SUCCESS);
}

t_bool				set_graph_vars(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	lem_in->graph_vars.source_ants = NANTS;
	lem_in->graph_vars.sink_ants = 0;
	lem_in->graph_vars.turns = 0;
	return (SUCCESS);
}

t_bool				get_graph(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	QUE = TEMP_QUE;
	while (QUE)
	{
		if ((size_t)PATH_ROUND != INDEX)
		{
			TEMP_QUE = QUE;
			INDEX = (size_t)PATH_ROUND;
			return (SUCCESS);
		}
		QUE = QUE->next;
	}
	return (FAIL);
}

t_bool				delete_excess_paths(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	QUE = ALL_PATHS;
	while (QUE)
	{
		if ((size_t)PATH_ROUND != ROUND_NR)
			ft_addr_lstdel((t_adlist **)&QUE->address);
		QUE = QUE->next;
	}
	return (SUCCESS);
}

t_bool				clean_pathslist(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	while (!ALL_PATHS->address)
	{
		QUE = ALL_PATHS;
		ALL_PATHS = ALL_PATHS->next;
		ft_addr_lstdelone(&QUE);
	}
	QUE = ALL_PATHS;
	while (QUE->next)
	{
		if (!QUE->next->address)
		{
			ft_addr_lstdel(&QUE->next);
			break ;
		}
		QUE = QUE->next;
	}
	return (SUCCESS);
}

t_bool				finish_graph_calculation(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->graph_vars.sink_ants < NANTS)
		return (FAIL);
	return (SUCCESS);
}

t_bool				calculate_turn(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	QUE = TEMP_QUE;
	while (QUE)
	{
		if ((size_t)PATH_ROUND != INDEX)
			break;
		if (lem_in->graph_vars.turns + 1 < (size_t)PATH_LENGTH)
			--(lem_in->graph_vars.source_ants);
		else
			++(lem_in->graph_vars.sink_ants);
		QUE = QUE->next;
	}
	++(lem_in->graph_vars.turns);
	return (SUCCESS);
}

t_bool				update_stored_graph(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->nturns > lem_in->graph_vars.turns)
	{
		lem_in->nturns = lem_in->graph_vars.turns;
		ROUND_NR = INDEX;
	}
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_set_global_vars;
	TRANSITIONS[s_set_global_vars][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_set_global_vars][SUCCESS] = s_set_graph_vars;
	TRANSITIONS[s_set_graph_vars][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_set_graph_vars][SUCCESS] = s_get_graph;
	TRANSITIONS[s_get_graph][FAIL] = s_delete_excess_paths;
	TRANSITIONS[s_get_graph][SUCCESS] = s_finish_graph_calculation;
	TRANSITIONS[s_delete_excess_paths][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_delete_excess_paths][SUCCESS] = s_clean_pathslist;
	TRANSITIONS[s_clean_pathslist][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_clean_pathslist][SUCCESS] = s_print_tables_cg;
	TRANSITIONS[s_finish_graph_calculation][FAIL] = s_calculate_turn;
	TRANSITIONS[s_finish_graph_calculation][SUCCESS] = s_update_stored_graph;
	TRANSITIONS[s_calculate_turn][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_calculate_turn][SUCCESS] = s_finish_graph_calculation;
	TRANSITIONS[s_update_stored_graph][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_update_stored_graph][SUCCESS] = s_set_graph_vars;
	TRANSITIONS[s_print_tables_cg][FAIL] = s_uninstall_machine_cg;
	TRANSITIONS[s_print_tables_cg][SUCCESS] = s_uninstall_machine_cg;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_cg] = NULL;
	EVENTS[s_set_global_vars] = set_global_vars;
	EVENTS[s_set_graph_vars] = set_graph_vars;
	EVENTS[s_get_graph] = get_graph;
	EVENTS[s_delete_excess_paths] = delete_excess_paths;
	EVENTS[s_clean_pathslist] = clean_pathslist;
	EVENTS[s_finish_graph_calculation] = finish_graph_calculation;
	EVENTS[s_calculate_turn] = calculate_turn;
	EVENTS[s_update_stored_graph] = update_stored_graph;
	EVENTS[s_print_tables_cg] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_cg);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								choose_graph(t_project *lem_in)
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
