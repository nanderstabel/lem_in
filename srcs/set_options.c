/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_options.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 14:50:28 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/15 17:48:27 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool				read_argument(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (lem_in->argc > 1)
	{
		--lem_in->argc;
		++lem_in->argv;
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				find_dash(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (**lem_in->argv == '-')
	{
		++(*lem_in->argv);
		return (SUCCESS);
	}
	return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}

static void			check_options(t_project *lem_in)
{
	if (**lem_in->argv == 'g')
		lem_in->flags |= DEBUG_O;
	else if (**lem_in->argv == 'r')
		lem_in->flags |= ROOMS_O;
	else if (**lem_in->argv == 'l')
		lem_in->flags |= LINKS_O;
	else if (**lem_in->argv == 'e')
		lem_in->flags |= ERROR_O;
	else if (**lem_in->argv == 'd')
		lem_in->flags |= DFS_O;
	else if (**lem_in->argv == 'p')
		lem_in->flags |= PATHS_O;
	else if (**lem_in->argv == 'a')
		lem_in->flags |= AUGMENT_O;
	else if (**lem_in->argv == 'c')
		lem_in->flags |= COUNT_O;
	else if (**lem_in->argv == 'b')
		lem_in->flags |= BLANK_O;
}

t_bool				find_option(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (ft_strchr(OPTIONS, **lem_in->argv) && **lem_in->argv)
	{
		if (**lem_in->argv == 'u')
			return (FAIL);
		check_options(lem_in);
		++(*lem_in->argv);
		return (SUCCESS);
	}
	return (FAIL);
}

t_bool				validate_argument(t_project *lem_in)
{
	if (lem_in->flags & DEBUG_O)
		ft_printf("\t%s\n", __func__);
	if (**lem_in->argv == 0 && *(*lem_in->argv - 1) != '-')
		return (SUCCESS);
	return (error_log(lem_in, ft_strjoin("\t- ", __func__), FAIL));
}

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

t_bool								set_options(t_project *lem_in)
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
