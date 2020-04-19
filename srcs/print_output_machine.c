/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_output_machine.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:10:56 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/19 10:24:12 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				print_input(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->flags & BLANK_O)
		return (FAIL);
	ft_printf("%s\n", lem_in->input_string);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_install_machine_rms][FAIL] = \
		s_uninstall_machine_po;
	(*mconfig)->transitions[s_install_machine_rms][SUCCESS] = s_print_input;
	(*mconfig)->transitions[s_print_input][FAIL] = s_print_tables_po;
	(*mconfig)->transitions[s_print_input][SUCCESS] = s_sort_paths;
	(*mconfig)->transitions[s_sort_paths][FAIL] = s_uninstall_machine_po;
	(*mconfig)->transitions[s_sort_paths][SUCCESS] = s_spawn_ants;
	(*mconfig)->transitions[s_spawn_ants][FAIL] = s_uninstall_machine_po;
	(*mconfig)->transitions[s_spawn_ants][SUCCESS] = s_move_all_ants;
	(*mconfig)->transitions[s_move_all_ants][FAIL] = s_print_tables_po;
	(*mconfig)->transitions[s_move_all_ants][SUCCESS] = s_spawn_ants;
	(*mconfig)->transitions[s_print_tables_po][FAIL] = s_uninstall_machine_po;
	(*mconfig)->transitions[s_print_tables_po][SUCCESS] = \
		s_uninstall_machine_po;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_po] = NULL;
	(*mconfig)->events[s_print_input] = print_input;
	(*mconfig)->events[s_sort_paths] = sort_paths;
	(*mconfig)->events[s_spawn_ants] = spawn_ants;
	(*mconfig)->events[s_move_all_ants] = move_all_ants;
	(*mconfig)->events[s_print_tables_po] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_po);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				print_output(t_project *lem_in)
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
