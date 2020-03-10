/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:57:21 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/10 17:53:51 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// t_bool				print_rooms(t_project *lem_in)
// {
// 	if (FLAGS & DEBUG_O)
// 		ft_printf("\t%s\n", __func__);
// 	return (SUCCESS);
// }

// static void			get_transitions(t_mconfig **mconfig)
// {
// 	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_rms;
// 	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_initialize_table_rms;
// 	TRANSITIONS[s_initialize_table_rms][FAIL] = s_uninstall_machine_rms;
// 	TRANSITIONS[s_initialize_table_rms][SUCCESS] = s_set_line_rms;
// 	TRANSITIONS[s_set_line_rms][FAIL] = s_uninstall_machine_rms;
// 	TRANSITIONS[s_set_line_rms][SUCCESS] = s_get_type;
// 	TRANSITIONS[s_get_type][FAIL] = s_print_rooms;
// 	TRANSITIONS[s_get_type][SUCCESS] = s_store_room;
// 	TRANSITIONS[s_store_room][FAIL] = s_uninstall_machine_rms;
// 	TRANSITIONS[s_store_room][SUCCESS] = s_get_type;
// 	TRANSITIONS[s_print_rooms][FAIL] = s_uninstall_machine_rms;
// 	TRANSITIONS[s_print_rooms][SUCCESS] = s_uninstall_machine_rms;
// }

// static void			get_events(t_mconfig **mconfig)
// {
// 	EVENTS[s_install_machine_rms] = NULL;
// 	EVENTS[s_initialize_table_rms] = initialize_table_rms;
// 	EVENTS[s_set_line_rms] = set_line_rms;
// 	EVENTS[s_get_type] = get_type;
// 	EVENTS[s_store_room] = store_room;
// 	EVENTS[s_print_rooms] = print_rooms;
// }

// static t_mconfig	*states(void)
// {
// 	t_mconfig		*mconfig;

// 	mconfig = malloc_mconfig(s_uninstall_machine_rms);
// 	get_transitions(&mconfig);
// 	get_events(&mconfig);
// 	return (mconfig);
// }

t_bool								find_paths(t_project *lem_in)
{
	// t_machine	*machine;

	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	// if (install_machine(&machine, states()) == SUCCESS)
	// 	run_machine(machine, lem_in);
	// uninstall_machine(&machine);
	// if (ERROR)
	// 	return (ERROR_LOG(FAIL));
	return (SUCCESS);
}
