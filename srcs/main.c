/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/07 09:33:12 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			initialize_project(t_project **lem_in)
{
	*lem_in = (t_project *)ft_memalloc(sizeof(t_project));
	(*lem_in)->round_nr = 1;
}

/*
** The next three functions together form the framework of the lem_in project.
*/

static void			get_transitions(t_mconfig **mconfig)
{
	TRANSITIONS[s_install_machine][FAIL] = s_uninstall_machine;
	TRANSITIONS[s_install_machine][SUCCESS] = s_set_options;
	TRANSITIONS[s_set_options][FAIL] = s_print_error;
	TRANSITIONS[s_set_options][SUCCESS] = s_validate_input;
	TRANSITIONS[s_validate_input][FAIL] = s_print_error;
	TRANSITIONS[s_validate_input][SUCCESS] = s_store_rooms;
	TRANSITIONS[s_store_rooms][FAIL] = s_print_error;
	TRANSITIONS[s_store_rooms][SUCCESS] = s_store_links;
	TRANSITIONS[s_store_links][FAIL] = s_print_error;
	TRANSITIONS[s_store_links][SUCCESS] = s_label_graph;
	TRANSITIONS[s_label_graph][FAIL] = s_find_paths;
	TRANSITIONS[s_label_graph][SUCCESS] = s_find_paths;//s_choose_graph;
	TRANSITIONS[s_find_paths][FAIL] = s_print_error;
	TRANSITIONS[s_find_paths][SUCCESS] = s_choose_graph;//s_augment_paths;
	TRANSITIONS[s_augment_paths][FAIL] = s_print_error;
	TRANSITIONS[s_augment_paths][SUCCESS] = s_label_graph;
	TRANSITIONS[s_choose_graph][FAIL] = s_print_error;
	TRANSITIONS[s_choose_graph][SUCCESS] = s_move_ants;
	TRANSITIONS[s_move_ants][FAIL] = s_print_error;
	TRANSITIONS[s_move_ants][SUCCESS] = s_print_output;
	TRANSITIONS[s_print_error][FAIL] = s_print_error;
	TRANSITIONS[s_print_error][SUCCESS] = s_free_project;
	TRANSITIONS[s_print_output][FAIL] = s_print_error;
	TRANSITIONS[s_print_output][SUCCESS] = s_free_project;
	TRANSITIONS[s_free_project][FAIL] = s_print_error;
	TRANSITIONS[s_free_project][SUCCESS] = s_uninstall_machine;
}

static void			get_events(t_mconfig **mconfig)
{
	EVENTS[s_install_machine] = NULL;
	EVENTS[s_set_options] = set_options;
	EVENTS[s_validate_input] = validate_input;
	EVENTS[s_store_rooms] = store_rooms;
	EVENTS[s_store_links] = store_links;
	EVENTS[s_label_graph] = label_graph;
	EVENTS[s_find_paths] = find_paths;
	EVENTS[s_augment_paths] = augmenting_paths;
	EVENTS[s_choose_graph] = choose_graph;
	EVENTS[s_move_ants] = move_ants;
	EVENTS[s_print_error] = print_error;
	EVENTS[s_print_output] = print_output;
	EVENTS[s_free_project] = free_project;
}

/*
** Returns the configurated mconfig struct. Important to note here is that
** the size you give to malloc_mconfig sould be the state with the highest
** value in the corresponding enum.
*/

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine);
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

	initialize_project(&lem_in);
	ARGC = argc;
	ARGV = argv;
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	return (0);
}
