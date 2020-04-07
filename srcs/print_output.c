/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_output.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 19:10:56 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/07 12:54:47 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

enum
{
	s_install_machine_po,
	s_print_tables_po,
	s_uninstall_machine_po,
}	e_state_po;

t_bool				proto(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_rms][FAIL] = s_uninstall_machine_po;
	TRANSITIONS[s_install_machine_rms][SUCCESS] = s_uninstall_machine_po;
	TRANSITIONS[s_print_tables_po][FAIL] = s_uninstall_machine_po;
	TRANSITIONS[s_print_tables_po][SUCCESS] = s_uninstall_machine_po;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_po] = NULL;
	EVENTS[s_print_tables_po] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_po);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								print_output(t_project *lem_in)
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
