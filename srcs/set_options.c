/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_options.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 14:50:28 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 20:50:34 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				read_argument(void *project)
{
	t_project	*lem_in;

	lem_in = (t_project *)project;
	ft_printf("Currently: %s\n", __func__);
	if (ARGC > 1)
	{
		--ARGC;
		++ARGV;
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				find_dash(void *project)
{
	t_project	*lem_in;

	lem_in = (t_project *)project;
	ft_printf("Currently: %s\n", __func__);
	if (**ARGV == '-')
	{
		++(*ARGV);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				find_option(void *project)
{
	t_project	*lem_in;

	lem_in = (t_project *)project;
	ft_printf("Currently: %s\n", __func__);
	if (ft_strchr(OPTIONS, **ARGV) && **ARGV != 0)
	{
		if (**ARGV == 'd')
			FLAGS |= DEBUG;
		++(*ARGV);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				validate_argument(void *project)
{
	t_project	*lem_in;

	lem_in = (t_project *)project;
	ft_printf("Currently: %s\n", __func__);
	if (**ARGV == 0)
		return (SUCCESS);
	return (FAIL);
}

t_bool				find_error_opt(void *project)
{
	t_project	*lem_in;

	lem_in = (t_project *)project;
	ft_printf("Currently: %s\n", __func__);
	ft_printf("Machine was trying to %i")
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine_opt][FAIL] = s_uninstall_machine_opt;
	TRANSITIONS[s_install_machine_opt][SUCCESS] = s_read_argument_opt;
	TRANSITIONS[s_read_argument_opt][FAIL] = s_uninstall_machine_opt;
	TRANSITIONS[s_read_argument_opt][SUCCESS] = s_find_dash_opt;
	TRANSITIONS[s_find_dash_opt][FAIL] = s_find_error_opt;
	TRANSITIONS[s_find_dash_opt][SUCCESS] = s_find_option_opt;
	TRANSITIONS[s_find_option_opt][FAIL] = s_validate_argument_opt;
	TRANSITIONS[s_find_option_opt][SUCCESS] = s_find_option_opt;
	TRANSITIONS[s_validate_argument_opt][FAIL] = s_find_error_opt;
	TRANSITIONS[s_validate_argument_opt][SUCCESS] = s_read_argument_opt;
	TRANSITIONS[s_find_error_opt][FAIL] = s_find_error_opt;
	TRANSITIONS[s_find_error_opt][SUCCESS] = s_uninstall_machine_opt;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine_opt] = NULL;
	EVENTS[s_read_argument_opt] = read_argument;
	EVENTS[s_find_dash_opt] = find_dash;
	EVENTS[s_find_option_opt] = find_option;
	EVENTS[s_validate_argument_opt] = validate_argument;
	EVENTS[s_find_error_opt] = find_error_opt;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_opt);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool								set_options(void *project)
{
	t_project	*lem_in;
	t_machine	*machine;

	lem_in = (t_project *)project;
	ft_printf("Currently: %s\n", __func__);
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	if (lem_in->error)
		return (FAIL);
	return (SUCCESS);
}
