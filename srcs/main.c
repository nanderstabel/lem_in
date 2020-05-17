/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 17:31:03 by nstabel       #+#    #+#                 */
/*   Updated: 2020/05/17 22:05:20 by nstabel       ########   odam.nl         */
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
	(*mconfig)->transitions[s_install_machine][FAIL] = s_uninstall_machine;
	(*mconfig)->transitions[s_install_machine][SUCCESS] = s_set_options;
	(*mconfig)->transitions[s_set_options][FAIL] = s_print_error;
	(*mconfig)->transitions[s_set_options][SUCCESS] = s_validate_input;
	(*mconfig)->transitions[s_validate_input][FAIL] = s_print_error;
	(*mconfig)->transitions[s_validate_input][SUCCESS] = s_store_rooms;
	(*mconfig)->transitions[s_store_rooms][FAIL] = s_print_error;
	(*mconfig)->transitions[s_store_rooms][SUCCESS] = s_store_links;
	(*mconfig)->transitions[s_store_links][FAIL] = s_print_error;
	(*mconfig)->transitions[s_store_links][SUCCESS] = s_label_graph;
	(*mconfig)->transitions[s_label_graph][SUCCESS] = s_find_paths;
	(*mconfig)->transitions[s_label_graph][FAIL] = s_choose_graph;
	(*mconfig)->transitions[s_find_paths][FAIL] = s_label_graph_s_to_t;
	(*mconfig)->transitions[s_find_paths][SUCCESS] = s_free_project;//s_label_graph;
	(*mconfig)->transitions[s_label_graph_s_to_t][SUCCESS] = s_augment_paths;
	(*mconfig)->transitions[s_augment_paths][FAIL] = s_choose_graph;
	(*mconfig)->transitions[s_augment_paths][SUCCESS] = s_label_graph;
	(*mconfig)->transitions[s_choose_graph][FAIL] = s_print_error;
	(*mconfig)->transitions[s_choose_graph][SUCCESS] = s_print_output;
	(*mconfig)->transitions[s_print_error][FAIL] = s_print_error;
	(*mconfig)->transitions[s_print_error][SUCCESS] = s_free_project;
	(*mconfig)->transitions[s_print_output][FAIL] = s_print_error;
	(*mconfig)->transitions[s_print_output][SUCCESS] = s_free_project;
	(*mconfig)->transitions[s_free_project][FAIL] = s_print_error;
	(*mconfig)->transitions[s_free_project][SUCCESS] = s_uninstall_machine;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine] = NULL;
	(*mconfig)->events[s_set_options] = set_options;
	(*mconfig)->events[s_validate_input] = validate_input;
	(*mconfig)->events[s_store_rooms] = store_rooms;
	(*mconfig)->events[s_store_links] = store_links;
	(*mconfig)->events[s_label_graph] = label_graph;
	(*mconfig)->events[s_label_graph_s_to_t] = label_graph_s_to_t;
	(*mconfig)->events[s_find_paths] = find_paths;
	(*mconfig)->events[s_augment_paths] = augmenting_paths;
	(*mconfig)->events[s_choose_graph] = choose_graph;
	(*mconfig)->events[s_print_error] = print_error;
	(*mconfig)->events[s_print_output] = print_output;
	(*mconfig)->events[s_free_project] = free_project;
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
	lem_in->argc = argc;
	lem_in->argv = argv;
	if (install_machine(&machine, states()) == SUCCESS)
		run_machine(machine, lem_in);
	uninstall_machine(&machine);
	return (0);
}
