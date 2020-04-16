/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_options.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 14:50:28 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 18:50:56 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				print_usage_message(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	ft_printf("Usage: ./lem-in [-%s] < map\n", OPTIONS);
	ft_printf("Pathfinder which moves 'ants' from a start room to an end ");
	ft_printf("room, using a given map, in the least amount of steps\n");
	ft_printf("\t-a\t\tprints the steps taken during augmenting\n");
	ft_printf("\t-b\t\tprevents printing output\n");
	ft_printf("\t-c\t\tadds a turn counter to the output\n");
	ft_printf("\t-d\t\tprints the steps taken during pathfinding (dfs)\n");
	ft_printf("\t-e\t\tshows where an error occured, if there was any\n");
	ft_printf(\
	"\t-g\t\tdebug mode: shows executed functions in chronological order\n");
	ft_printf("\t-l\t\tprints hashtables containing all links\n");
	ft_printf("\t-p\t\tshows all paths ordered by round number\n");
	ft_printf("\t-r\t\tprints hashtables containing all rooms\n");
	ft_printf("\t-u\t\tshows usage message\n");
	return (SUCCESS);
}

static void			get_transitions(t_mconfig **mconfig)
{
	t_state		**transitions;

	transitions = (*mconfig)->transitions;
	transitions[s_install_machine_opt][FAIL] = s_uninstall_machine_opt;
	transitions[s_install_machine_opt][SUCCESS] = s_read_argument_opt;
	transitions[s_read_argument_opt][FAIL] = s_uninstall_machine_opt;
	transitions[s_read_argument_opt][SUCCESS] = s_find_dash_opt;
	transitions[s_find_dash_opt][FAIL] = s_uninstall_machine_opt;
	transitions[s_find_dash_opt][SUCCESS] = s_find_option_opt;
	transitions[s_find_option_opt][FAIL] = s_validate_argument_opt;
	transitions[s_find_option_opt][SUCCESS] = s_find_option_opt;
	transitions[s_validate_argument_opt][FAIL] = s_print_usage_message;
	transitions[s_validate_argument_opt][SUCCESS] = s_read_argument_opt;
	transitions[s_print_usage_message][FAIL] = s_uninstall_machine_opt;
	transitions[s_print_usage_message][SUCCESS] = s_uninstall_machine_opt;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_opt] = NULL;
	(*mconfig)->events[s_read_argument_opt] = read_argument;
	(*mconfig)->events[s_find_dash_opt] = find_dash;
	(*mconfig)->events[s_find_option_opt] = find_option;
	(*mconfig)->events[s_validate_argument_opt] = validate_argument;
	(*mconfig)->events[s_print_usage_message] = print_usage_message;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_opt);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				set_options(t_project *lem_in)
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
