/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_options.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 14:50:28 by nstabel        #+#    #+#                */
/*   Updated: 2020/03/02 14:48:00 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				read_argument(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ARGC > 1)
	{
		--ARGC;
		++ARGV;
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				find_dash(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (**ARGV == '-')
	{
		++(*ARGV);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				find_option(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strchr(OPTIONS, **ARGV))
	{
		if (**ARGV == 'g')
			FLAGS |= DEBUG_O;
		if (**ARGV == 'r')
			FLAGS |= ROOMS_O;
		if (**ARGV == 'l')
			FLAGS |= LINKS_O;
		++(*ARGV);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				validate_argument(t_project *lem_in)
{
	if (FLAGS & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (**ARGV == 0)
		return (SUCCESS);
	return (FAIL);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_opt][FAIL] = s_uninstall_machine_opt;
	TRANSITIONS[s_install_machine_opt][SUCCESS] = s_read_argument_opt;
	TRANSITIONS[s_read_argument_opt][FAIL] = s_uninstall_machine_opt;
	TRANSITIONS[s_read_argument_opt][SUCCESS] = s_find_dash_opt;
	TRANSITIONS[s_find_dash_opt][FAIL] = s_uninstall_machine_opt;
	TRANSITIONS[s_find_dash_opt][SUCCESS] = s_find_option_opt;
	TRANSITIONS[s_find_option_opt][FAIL] = s_validate_argument_opt;
	TRANSITIONS[s_find_option_opt][SUCCESS] = s_find_option_opt;
	TRANSITIONS[s_validate_argument_opt][FAIL] = s_uninstall_machine_opt;
	TRANSITIONS[s_validate_argument_opt][SUCCESS] = s_read_argument_opt;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_opt] = NULL;
	EVENTS[s_read_argument_opt] = read_argument;
	EVENTS[s_find_dash_opt] = find_dash;
	EVENTS[s_find_option_opt] = find_option;
	EVENTS[s_validate_argument_opt] = validate_argument;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_opt);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								set_options(t_project *lem_in)
{
	t_machine	*machine;

	if (FLAGS & DEBUG_O)
		ft_printf("%s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (ERROR)
		return (FAIL);
	return (SUCCESS);
}
