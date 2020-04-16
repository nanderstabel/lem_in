/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_links.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 12:56:15 by nstabel       #+#    #+#                 */
/*   Updated: 2020/04/16 19:04:01 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			get_transitions(t_mconfig **mconfig)
{
	t_state		**transitions;

	transitions = (*mconfig)->transitions;
	transitions[s_install_machine_lks][FAIL] = s_uninstall_machine_lks;
	transitions[s_install_machine_lks][SUCCESS] = s_initialize_table_lks;
	transitions[s_initialize_table_lks][FAIL] = s_uninstall_machine_lks;
	transitions[s_initialize_table_lks][SUCCESS] = s_save_roomnames;
	transitions[s_save_roomnames][FAIL] = s_uninstall_machine_lks;
	transitions[s_save_roomnames][SUCCESS] = s_find_first_room;
	transitions[s_find_first_room][FAIL] = s_uninstall_machine_lks;
	transitions[s_find_first_room][SUCCESS] = s_find_second_room;
	transitions[s_find_second_room][FAIL] = s_uninstall_machine_lks;
	transitions[s_find_second_room][SUCCESS] = s_store_link;
	transitions[s_store_link][FAIL] = s_set_line;
	transitions[s_store_link][SUCCESS] = s_add_room_to_link;
	transitions[s_add_room_to_link][FAIL] = s_uninstall_machine_lks;
	transitions[s_add_room_to_link][SUCCESS] = s_add_link_to_room;
	transitions[s_add_link_to_room][FAIL] = s_uninstall_machine_lks;
	transitions[s_add_link_to_room][SUCCESS] = s_swap_rooms;
	transitions[s_swap_rooms][FAIL] = s_set_line;
	transitions[s_swap_rooms][SUCCESS] = s_store_link;
	transitions[s_set_line][FAIL] = s_print_tables_lks;
	transitions[s_set_line][SUCCESS] = s_save_roomnames;
	transitions[s_print_tables_lks][FAIL] = s_uninstall_machine_lks;
	transitions[s_print_tables_lks][SUCCESS] = s_uninstall_machine_lks;
}

static void			get_events(t_mconfig **mconfig)
{
	(*mconfig)->events[s_install_machine_lks] = NULL;
	(*mconfig)->events[s_initialize_table_lks] = initialize_table_lks;
	(*mconfig)->events[s_save_roomnames] = save_roomnames;
	(*mconfig)->events[s_find_first_room] = find_first_room;
	(*mconfig)->events[s_find_second_room] = find_second_room;
	(*mconfig)->events[s_store_link] = store_link;
	(*mconfig)->events[s_add_room_to_link] = add_room_to_link;
	(*mconfig)->events[s_add_link_to_room] = add_link_to_room;
	(*mconfig)->events[s_swap_rooms] = swap_rooms;
	(*mconfig)->events[s_set_line] = set_line;
	(*mconfig)->events[s_print_tables_lks] = print_tables;
}

static t_mconfig	*states(void)
{
	t_mconfig		*mconfig;

	mconfig = malloc_mconfig(s_uninstall_machine_lks);
	get_transitions(&mconfig);
	get_events(&mconfig);
	return (mconfig);
}

t_bool				store_links(t_project *lem_in)
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
