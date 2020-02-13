/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/13 19:44:20 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** In the next three functions a two-dimensional array is installed which will
** be used to update to state of the machine everytime an event returns a
** transition value.
*/

void			malloc_transition_table(t_machine **machine)
{
	t_state		proxy;

	proxy = 0;
	(*machine)->transition_table = \
		(t_state **)malloc(sizeof(t_state *) * (*machine)->size);
	while (proxy < (*machine)->size)
	{
		(*machine)->transition_table[proxy] = \
			(t_state *)malloc(sizeof(t_state) * 2);
		++proxy;
	}
}

void			fill_transition_table(t_machine **machine)
{
	(*machine)->transition_table[install_machine][FAIL] = idle;
	(*machine)->transition_table[install_machine][SUCCESS] = set_options;
	(*machine)->transition_table[set_options][FAIL] = find_error;
	(*machine)->transition_table[set_options][SUCCESS] = validate_input;
	(*machine)->transition_table[validate_input][FAIL] = find_error;
	(*machine)->transition_table[validate_input][SUCCESS] = store_rooms;
	(*machine)->transition_table[store_rooms][FAIL] = find_error;
	(*machine)->transition_table[store_rooms][SUCCESS] = store_links;
	(*machine)->transition_table[store_links][FAIL] = find_error;
	(*machine)->transition_table[store_links][SUCCESS] = label_graph;
	(*machine)->transition_table[label_graph][FAIL] = find_paths;
	(*machine)->transition_table[label_graph][SUCCESS] = move_ants;
	(*machine)->transition_table[find_paths][FAIL] = find_error;
	(*machine)->transition_table[find_paths][SUCCESS] = augment_paths;
	(*machine)->transition_table[augment_paths][FAIL] = find_error;
	(*machine)->transition_table[augment_paths][SUCCESS] = label_graph;
	(*machine)->transition_table[move_ants][FAIL] = find_error;
	(*machine)->transition_table[move_ants][SUCCESS] = print_output;
	(*machine)->transition_table[find_error][FAIL] = find_error;
	(*machine)->transition_table[find_error][SUCCESS] = print_output;
	(*machine)->transition_table[print_output][FAIL] = find_error;
	(*machine)->transition_table[print_output][SUCCESS] = uninstall_machine;
	(*machine)->transition_table[uninstall_machine][FAIL] = find_error;
	(*machine)->transition_table[uninstall_machine][SUCCESS] = idle;
}

void			install_transitions(t_machine **machine)
{
	malloc_transition_table(machine);
	fill_transition_table(machine);
}

/*
** In the next three functions an array of function pointers is installed which
** links the possible states of the machine to the corresponding events that
** are associated with those states.
*/

void			malloc_event_table(t_machine **machine)
{
	(*machine)->event = \
		(t_event *)malloc(sizeof(t_event) * (*machine)->size);
}

void			fill_event_table(t_machine **machine)
{
	(*machine)->event[install_machine] = NULL;
	(*machine)->event[set_options] = setting_options;
	(*machine)->event[validate_input] = validating_input;
	(*machine)->event[store_rooms] = storing_rooms;
	(*machine)->event[store_links] = storing_links;
	(*machine)->event[label_graph] = labeling_graph;
	(*machine)->event[find_paths] = finding_paths;
	(*machine)->event[augment_paths] = augmenting_paths;
	(*machine)->event[move_ants] = moving_ants;
	(*machine)->event[find_error] = finding_error;
	(*machine)->event[print_output] = printing_output;
	(*machine)->event[uninstall_machine] = uninstalling_machine;
}

void			install_events(t_machine **machine)
{
	malloc_event_table(machine);
	fill_event_table(machine);
}

/*
** 'Installing' the machine means to allocate sufficient memory for the machine
** variable. At the end of this function, the transition- and event tables are
** installed.
*/

void			install(t_machine **machine, t_state size)
{
	*machine = (t_machine *)malloc(sizeof(t_machine));
	(*machine)->current_state = 0;
	(*machine)->size = size;
	install_transitions(machine);
	install_events(machine);
	(*machine)->transition = SUCCESS;
}

/*
** For the program to be able to continue, it needs to update it's current
** state. To do this, it needs a transition value ('FAIL' or 'SUCCES') provided
** by an event. Both the current state and the transition value are used as
** indices in the transition table to find the new state of the machine.
*/

void			update_current_state(t_machine *machine)
{
	machine->current_state = \
		machine->transition_table[machine->current_state][machine->transition];
}

/*
** Depending on the current state, a corresponding event is executed. In this
** function the current state is used as an index for the array of function
** pointers ('machine->event'). Everytime an event occurs, it returns a
** transition ('FAIL' or 'SUCCES').
*/

void			execute_event(t_machine *machine, t_project *lem_in)
{
	machine->transition = machine->event[machine->current_state](lem_in);
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

int				main(int argc, char **argv)
{
	t_machine	*machine;
	t_project	*lem_in;

	install(&machine, idle);
	lem_in = (t_project *)ft_memalloc(sizeof(t_project));
	lem_in->argc = argc;
	lem_in->argv = argv;
	while (SUCCESS)
	{
		update_current_state(machine);
		if (machine->current_state == idle)
			break ;
		execute_event(machine, lem_in);
	}
	free(machine);
	machine = NULL;
	return (0);
}
