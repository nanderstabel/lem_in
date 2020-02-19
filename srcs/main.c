/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/19 15:00:58 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** The next three functions together form the framework of the lem_in project.
*/

static void			get_transitions(t_mconfig **mconfig)
{
	(*mconfig)->transitions[s_install_machine][FAIL] = s_idle;
	(*mconfig)->transitions[s_install_machine][SUCCESS] = s_set_options;
	(*mconfig)->transitions[s_set_options][FAIL] = s_find_error;
	(*mconfig)->transitions[s_set_options][SUCCESS] = s_validate_input;
	(*mconfig)->transitions[s_validate_input][FAIL] = s_find_error;
	(*mconfig)->transitions[s_validate_input][SUCCESS] = s_store_rooms;
	(*mconfig)->transitions[s_store_rooms][FAIL] = s_find_error;
	(*mconfig)->transitions[s_store_rooms][SUCCESS] = s_store_links;
	(*mconfig)->transitions[s_store_links][FAIL] = s_find_error;
	(*mconfig)->transitions[s_store_links][SUCCESS] = s_label_graph;
	(*mconfig)->transitions[s_label_graph][FAIL] = s_find_paths;
	(*mconfig)->transitions[s_label_graph][SUCCESS] = s_move_ants;
	(*mconfig)->transitions[s_find_paths][FAIL] = s_find_error;
	(*mconfig)->transitions[s_find_paths][SUCCESS] = s_augment_paths;
	(*mconfig)->transitions[s_augment_paths][FAIL] = s_find_error;
	(*mconfig)->transitions[s_augment_paths][SUCCESS] = s_label_graph;
	(*mconfig)->transitions[s_move_ants][FAIL] = s_find_error;
	(*mconfig)->transitions[s_move_ants][SUCCESS] = s_print_output;
	(*mconfig)->transitions[s_find_error][FAIL] = s_find_error;
	(*mconfig)->transitions[s_find_error][SUCCESS] = s_print_output;
	(*mconfig)->transitions[s_print_output][FAIL] = s_find_error;
	(*mconfig)->transitions[s_print_output][SUCCESS] = s_uninstall_machine;
	(*mconfig)->transitions[s_uninstall_machine][FAIL] = s_find_error;
	(*mconfig)->transitions[s_uninstall_machine][SUCCESS] = s_idle;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine] = NULL;
	(*mconfig)->events[s_set_options] = set_options;
	(*mconfig)->events[s_validate_input] = validate_input;
	(*mconfig)->events[s_store_rooms] = storing_rooms;
	(*mconfig)->events[s_store_links] = storing_links;
	(*mconfig)->events[s_label_graph] = labeling_graph;
	(*mconfig)->events[s_find_paths] = finding_paths;
	(*mconfig)->events[s_augment_paths] = augmenting_paths;
	(*mconfig)->events[s_move_ants] = moving_ants;
	(*mconfig)->events[s_find_error] = finding_error;
	(*mconfig)->events[s_print_output] = printing_output;
	(*mconfig)->events[s_uninstall_machine] = uninstalling_machine;
}

/*
** Returns the configurated mconfig struct. Important to note here is that
** the size you give to malloc_mconfig sould be the state with the highest
** value.
*/

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_idle);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

/*
** The main function is the entry point where the first instructions of the
** program are executed. A "machine" variable is declared and next, all the
** necessary structures for the program get installed as well as the command-
** line arguments. Next, the machine get's installed using the transition- and
** event tables. If this is successful, the run_machine function will loop
** through all the states and events which execute the rest of the program.
*/

int					main(int argc, char **argv)
{
	t_machine	*machine;
	t_project	*lem_in;

	lem_in = (t_project *)ft_memalloc(sizeof(t_project));
	lem_in->argc = argc;
	lem_in->argv = argv;
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	free(machine);
	machine = NULL;
	return (0);
}
