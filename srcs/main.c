/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/18 14:53:48 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_input **input)
{
	t_state		proxy;

	(*input)->transitions = (t_state **)malloc(sizeof(t_state *) * idle);
	proxy = install_machine;
	while (proxy < idle)
	{
		(*input)->transitions[proxy] = (t_state *)malloc(sizeof(t_state) * 2);
		++proxy;
	}
	(*input)->transitions[install_machine][FAIL] = idle;
	(*input)->transitions[install_machine][SUCCESS] = set_options;
	(*input)->transitions[set_options][FAIL] = find_error;
	(*input)->transitions[set_options][SUCCESS] = validate_input;
	(*input)->transitions[validate_input][FAIL] = find_error;
	(*input)->transitions[validate_input][SUCCESS] = store_rooms;
	(*input)->transitions[store_rooms][FAIL] = find_error;
	(*input)->transitions[store_rooms][SUCCESS] = store_links;
	(*input)->transitions[store_links][FAIL] = find_error;
	(*input)->transitions[store_links][SUCCESS] = label_graph;
	(*input)->transitions[label_graph][FAIL] = find_paths;
	(*input)->transitions[label_graph][SUCCESS] = move_ants;
	(*input)->transitions[find_paths][FAIL] = find_error;
	(*input)->transitions[find_paths][SUCCESS] = augment_paths;
	(*input)->transitions[augment_paths][FAIL] = find_error;
	(*input)->transitions[augment_paths][SUCCESS] = label_graph;
	(*input)->transitions[move_ants][FAIL] = find_error;
	(*input)->transitions[move_ants][SUCCESS] = print_output;
	(*input)->transitions[find_error][FAIL] = find_error;
	(*input)->transitions[find_error][SUCCESS] = print_output;
	(*input)->transitions[print_output][FAIL] = find_error;
	(*input)->transitions[print_output][SUCCESS] = uninstall_machine;
	(*input)->transitions[uninstall_machine][FAIL] = find_error;
	(*input)->transitions[uninstall_machine][SUCCESS] = idle;
}

static void			get_events(t_input **input)
{
	(*input)->events = (t_event *)malloc(sizeof(t_event) * idle);
	(*input)->events[install_machine] = NULL;
	(*input)->events[set_options] = setting_options;
	(*input)->events[validate_input] = validating_input;
	(*input)->events[store_rooms] = storing_rooms;
	(*input)->events[store_links] = storing_links;
	(*input)->events[label_graph] = labeling_graph;
	(*input)->events[find_paths] = finding_paths;
	(*input)->events[augment_paths] = augmenting_paths;
	(*input)->events[move_ants] = moving_ants;
	(*input)->events[find_error] = finding_error;
	(*input)->events[print_output] = printing_output;
	(*input)->events[uninstall_machine] = uninstalling_machine;
}

static t_input		*states(void)
{
	t_input		*input;

	input = (t_input *)ft_memalloc(sizeof(t_input));
	input->size = idle;
	get_transitions(&input);
	get_events(&input);
	return (input);
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
