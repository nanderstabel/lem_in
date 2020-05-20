/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tables_machine.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 11:08:09 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/20 13:40:12 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_install_machine_rms][FAIL] = \
		s_uninstall_machine_pt;
	(*mconfig)->transitions[s_install_machine_rms][SUCCESS] = s_print_rooms;
	(*mconfig)->transitions[s_print_rooms][FAIL] = s_uninstall_machine_pt;
	(*mconfig)->transitions[s_print_rooms][SUCCESS] = s_print_links;
	(*mconfig)->transitions[s_print_links][FAIL] = s_uninstall_machine_pt;
	(*mconfig)->transitions[s_print_links][SUCCESS] = s_print_paths;
	(*mconfig)->transitions[s_print_paths][FAIL] = s_uninstall_machine_pt;
	(*mconfig)->transitions[s_print_paths][SUCCESS] = s_uninstall_machine_pt;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_pt] = NULL;
	(*mconfig)->events[s_print_rooms] = print_rooms;
	(*mconfig)->events[s_print_links] = print_links;
	(*mconfig)->events[s_print_paths] = print_paths;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_pt);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				print_tables(t_project *lem_in)
{
	t_machine	*machine;

	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (lem_in->error)
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	return (SUCCESS);
}
