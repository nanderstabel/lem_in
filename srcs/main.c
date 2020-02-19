/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/19 11:02:45 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	(*mconfig)->transitions[install_machine][FAIL] = idle;
	(*mconfig)->transitions[install_machine][SUCCESS] = set_options;
	(*mconfig)->transitions[set_options][FAIL] = find_error;
	(*mconfig)->transitions[set_options][SUCCESS] = validate_input;
	(*mconfig)->transitions[validate_input][FAIL] = find_error;
	(*mconfig)->transitions[validate_input][SUCCESS] = store_rooms;
	(*mconfig)->transitions[store_rooms][FAIL] = find_error;
	(*mconfig)->transitions[store_rooms][SUCCESS] = store_links;
	(*mconfig)->transitions[store_links][FAIL] = find_error;
	(*mconfig)->transitions[store_links][SUCCESS] = label_graph;
	(*mconfig)->transitions[label_graph][FAIL] = find_paths;
	(*mconfig)->transitions[label_graph][SUCCESS] = move_ants;
	(*mconfig)->transitions[find_paths][FAIL] = find_error;
	(*mconfig)->transitions[find_paths][SUCCESS] = augment_paths;
	(*mconfig)->transitions[augment_paths][FAIL] = find_error;
	(*mconfig)->transitions[augment_paths][SUCCESS] = label_graph;
	(*mconfig)->transitions[move_ants][FAIL] = find_error;
	(*mconfig)->transitions[move_ants][SUCCESS] = print_output;
	(*mconfig)->transitions[find_error][FAIL] = find_error;
	(*mconfig)->transitions[find_error][SUCCESS] = print_output;
	(*mconfig)->transitions[print_output][FAIL] = find_error;
	(*mconfig)->transitions[print_output][SUCCESS] = uninstall_machine;
	(*mconfig)->transitions[uninstall_machine][FAIL] = find_error;
	(*mconfig)->transitions[uninstall_machine][SUCCESS] = idle;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[install_machine] = NULL;
	(*mconfig)->events[set_options] = setting_options;
	(*mconfig)->events[validate_input] = validating_input;
	(*mconfig)->events[store_rooms] = storing_rooms;
	(*mconfig)->events[store_links] = storing_links;
	(*mconfig)->events[label_graph] = labeling_graph;
	(*mconfig)->events[find_paths] = finding_paths;
	(*mconfig)->events[augment_paths] = augmenting_paths;
	(*mconfig)->events[move_ants] = moving_ants;
	(*mconfig)->events[find_error] = finding_error;
	(*mconfig)->events[print_output] = printing_output;
	(*mconfig)->events[uninstall_machine] = uninstalling_machine;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(idle);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

/*
** The main function is the entry point where the first instructions of the
** program are executed. A "machine" variable is declared and next, all the
** necessary structures for the program get installed as well as the command-
** line arguments. The while loop loops through all the events that combined
** will solve the lem_in project. In every loop, first the current state of the
** machine is updated. Second (unless the current state is 'idle') the event
** that corresponds to the current state is executed.
*/

int					main(int argc, char **argv)
{
	t_machine	*machine;
	t_project	*lem_in;

	lem_in = (t_project *)ft_memalloc(sizeof(t_project));
	lem_in->argc = argc;
	lem_in->argv = argv;
	if (installing_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	free(machine);
	machine = NULL;
	return (0);
}
