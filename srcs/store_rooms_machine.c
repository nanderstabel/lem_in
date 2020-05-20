/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_rooms.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 17:21:47 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 18:55:09 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_install_machine_rms][FAIL] = \
		s_uninstall_machine_rms;
	(*mconfig)->transitions[s_install_machine_rms][SUCCESS] = \
		s_initialize_table_rms;
	(*mconfig)->transitions[s_initialize_table_rms][FAIL] = \
		s_uninstall_machine_rms;
	(*mconfig)->transitions[s_initialize_table_rms][SUCCESS] = s_set_line_rms;
	(*mconfig)->transitions[s_set_line_rms][FAIL] = s_uninstall_machine_rms;
	(*mconfig)->transitions[s_set_line_rms][SUCCESS] = s_get_type;
	(*mconfig)->transitions[s_get_type][FAIL] = s_print_tables_rms;
	(*mconfig)->transitions[s_get_type][SUCCESS] = s_store_room;
	(*mconfig)->transitions[s_store_room][FAIL] = s_uninstall_machine_rms;
	(*mconfig)->transitions[s_store_room][SUCCESS] = s_get_type;
	(*mconfig)->transitions[s_print_tables_rms][FAIL] = s_uninstall_machine_rms;
	(*mconfig)->transitions[s_print_tables_rms][SUCCESS] = \
		s_uninstall_machine_rms;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_rms] = NULL;
	(*mconfig)->events[s_initialize_table_rms] = initialize_table_rms;
	(*mconfig)->events[s_set_line_rms] = set_line_rms;
	(*mconfig)->events[s_get_type] = get_type;
	(*mconfig)->events[s_store_room] = store_room;
	(*mconfig)->events[s_print_tables_rms] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_rms);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				store_rooms(t_project *lem_in)
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
