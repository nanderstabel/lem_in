/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input_machine.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:54:14 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/22 20:36:23 by zitzak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_vi);
	get_transitions_vi(&mconfig);
	get_events_vi(&mconfig);
	return (mconfig);
}

t_bool				validate_input(t_project *lem_in)
{
	t_machine		*machine;

	if (lem_in->flags & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (lem_in->error)
	{
		return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
	}
	return (SUCCESS);
}
